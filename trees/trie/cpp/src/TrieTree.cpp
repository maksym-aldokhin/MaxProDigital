#include "TrieTree.h"

#include <algorithm>
#include <optional>
#include <stdexcept>
#include <vector>

namespace {

constexpr size_t g_countOfSymbol = 26;

std::string toLower(const std::string &str)
{
	std::string res = str;
	std::ranges::transform(res, res.begin(), [](unsigned char c) { return std::tolower(c); });
	return res;
}
} // namespace

struct TrieTree::Node
{
	std::vector<std::shared_ptr<Node>> branches;
	bool lastSymbol{false};

	explicit Node()
	{
		branches.resize(g_countOfSymbol, nullptr);
	};

	~Node(){};

	std::shared_ptr<Node> find(const char c) const
	{
		return branches[c - 'a'];
	}

	std::shared_ptr<Node> insert(const char c)
	{
		auto &positionPtr = branches[c - 'a'];
		if (positionPtr) {
			return positionPtr;
		}
		positionPtr = std::make_shared<Node>();
		return positionPtr;
	}

	bool isEmptyLeaf() const
	{
		for (const auto &b : branches) {
			if (b) {
				return false;
			}
		}
		return true;
	}

	void remove(const char c)
	{
		branches[c - 'a'].reset();
	}

	std::optional<char> propose() const
	{
		for (auto it = branches.begin(); it != branches.end(); ++it) {
			if (*it) {
				return static_cast<char>('a' + std::distance(branches.begin(), it));
			}
		}
		return {};
	}
};

TrieTree::TrieTree()
    : m_root{std::make_unique<Node>()}
{
}

TrieTree::~TrieTree()
{
}

void TrieTree::insert(const std::string &word)
{
	if (word.empty()) {
		throw std::underflow_error("Word is empty");
		return;
	}

	insert(m_root, toLower(word));
}

void TrieTree::remove(const std::string &word)
{
	if (word.empty()) {
		throw std::underflow_error("Word is empty");
		return;
	}

	remove(m_root, toLower(word));
}

bool TrieTree::search(const std::string &word) const
{
	const auto found = findNode(m_root, toLower(word));
	return found && found->lastSymbol;
}

bool TrieTree::startsWith(const std::string &prefix) const
{
	const auto found = findNode(m_root, toLower(prefix));
	return found != nullptr;
}

std::string TrieTree::propose(const std::string &prefix) const
{
	const auto found = findNode(m_root, prefix);
	if (!found) {
		return prefix;
	}

	return prefix + propose(found);
}

std::shared_ptr<TrieTree::Node> TrieTree::findNode(
    const std::shared_ptr<TrieTree::Node> &node, const std::string &prefix) const
{
	if (prefix.empty()) {
		return node;
	}

	const auto found = node->find(prefix[0]);
	if (!found) {
		return {};
	}
	return findNode(found, prefix.substr(1, prefix.length() - 1));
}

void TrieTree::insert(const std::shared_ptr<Node> &node, const std::string &word)
{
	if (word.empty()) {
		node->lastSymbol = true;
		return;
	}

	auto inserted = node->insert(word[0]);
	if (!inserted) {
		return;
	}
	return insert(inserted, word.substr(1, word.length() - 1));
}

bool TrieTree::remove(const std::shared_ptr<Node> &node, const std::string &word)
{
	if (word.empty()) {
		node->lastSymbol = false;
		return node->isEmptyLeaf();
	}

	const auto found = node->find(word[0]);
	if (!found) {
		return false;
	}
	const auto res = remove(found, word.substr(1, word.length() - 1));
	if (res) {
		node->remove(word[0]);
		return node->isEmptyLeaf();
	}
	return false;
}

std::string TrieTree::propose(const std::shared_ptr<Node> &node) const
{
	const auto proposeChar = node->propose();
	if (proposeChar) {
		const auto found = node->find(*proposeChar);
		if (!found) {
			return {};
		}
		return std::string(1, *proposeChar) + propose(found);
	}
	return {};
}
