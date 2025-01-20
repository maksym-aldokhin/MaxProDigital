#include <memory>
#include <string>

class TrieTreePriority
{
public:
	explicit TrieTreePriority();
	~TrieTreePriority();

	void insert(const std::string &word);
	void remove(const std::string &word);

	bool search(const std::string &word) const;
	bool startsWith(const std::string &prefix) const;
	std::string propose(const std::string &prefix) const;

private:
	class Node;
	std::shared_ptr<Node> findNode(
	    const std::shared_ptr<TrieTreePriority::Node> &node,
	    const std::string &prefix,
	    bool considerPriority = false) const;
	void insert(const std::shared_ptr<TrieTreePriority::Node> &node, const std::string &word);
	bool remove(const std::shared_ptr<TrieTreePriority::Node> &node, const std::string &word);
	std::string propose(const std::shared_ptr<TrieTreePriority::Node> &node) const;

	std::shared_ptr<Node> m_root;
};
