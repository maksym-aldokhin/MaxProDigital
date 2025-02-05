#include <iterator>

template<class InputIt, class T = typename std::iterator_traits<InputIt>::value_type>
InputIt linerSearch(InputIt first, InputIt last, const T &value)
{
	for (; first != last; ++first) {
		if (*first == value) {
			return first;
		}
	}

	return last;
}

template<class InputIt, class T = typename std::iterator_traits<InputIt>::value_type>
int linerSearchIndex(InputIt first, InputIt last, const T &value)
{
	int position = 0;
	for (; first != last; ++first) {
		if (*first == value) {
			return position;
		}
		++position;
	}

	return -1;
}

template<typename T>
concept HasPushBack = requires (T t) {
	t.size();
	t.push_back(std::declval<typename T::value_type>());
	t.pop_back();
};

template<HasPushBack Container, class T = typename Container::value_type>
int sentinelSearchIndex(Container &data, const T &value)
{
	size_t length = data.size();
	data.push_back(value);
	size_t position = 0;

	auto it = data.begin();

	while (*it != value) {
		++it;
		++position;
	}

	data.pop_back();

	return position < length ? position : -1;
}

template<typename T>
concept IsArray = requires (T t, size_t i) {
	t.size();
	{
		t[i]
	} -> std::same_as<typename T::value_type &>;
	t.begin();
	t.end();
};

namespace private_func {

template<IsArray Container, class T = typename Container::value_type>
int binarySearchRecursiveIndex(const Container &data, const T &value, int begin, int end)
{
	if (end < begin) [[unlikely]] {
		return -1;
	}

	const int median = begin + (end - begin) / 2;

	if (data[median] < value) {
		return binarySearchRecursiveIndex(data, value, median + 1, end);
	} else if (data[median] > value) {
		return binarySearchRecursiveIndex(data, value, begin, median - 1);
	}
	return median;
}

} // namespace private_func

template<IsArray Container, class T = typename Container::value_type>
int binarySearchRecursiveIndex(const Container &data, const T &value, int begin = -1, int end = -1)
{
	if (begin == -1 && end == -1) {
		const auto newBegin = 0;
		const auto newEnd = data.size() - 1;
		return private_func::binarySearchRecursiveIndex(data, value, newBegin, newEnd);
	}

	return private_func::binarySearchRecursiveIndex(data, value, begin, end);
}

namespace private_func {

template<IsArray Container, class T = typename Container::value_type>
Container::const_iterator binarySearchIteratorRecursive(
    const Container &data,
    const T &value,
    const typename Container::const_iterator &beginIt,
    const typename Container::const_iterator &endIt)
{
	if (endIt < beginIt) [[unlikely]] {
		return data.end();
	}

	const auto medianIt = beginIt + std::distance(beginIt, endIt) / 2;

	if (*medianIt < value) {
		return binarySearchIteratorRecursive(data, value, medianIt + 1, endIt);
	} else if (*medianIt > value) {
		return binarySearchIteratorRecursive(data, value, beginIt, medianIt - 1);
	}
	return medianIt;
}

} // namespace private_func

template<IsArray Container, class T = typename Container::value_type>
Container::const_iterator binarySearchRecursive(
    const Container &data,
    const T &value,
    const typename Container::const_iterator &beginIt = typename Container::iterator{},
    const typename Container::const_iterator &endIt = typename Container::iterator{})
{
	if (data.begin() == data.end()) {
		return data.end();
	}
	if (beginIt == typename Container::iterator{} && endIt == typename Container::iterator{}) {
		const auto newBegin = data.begin();
		const auto newEnd = --data.end();
		return private_func::binarySearchIteratorRecursive(data, value, newBegin, newEnd);
	}

	return private_func::binarySearchIteratorRecursive(data, value, beginIt, endIt);
}

template<IsArray Container, class T = typename Container::value_type>
int binarySearchIterIndex(const Container &data, const T &value, int begin = -1, int end = -1)
{
	if (begin == -1 && end == -1) {
		begin = 0;
		end = data.size() - 1;
	}
	while (begin <= end) {
		int mid = begin + (end - begin) / 2;

		if (data[mid] < value) {
			begin = ++mid;
		} else if (data[mid] > value) {
			end = --mid;
		} else {
			return mid;
		}
	}

	return -1;
}

template<IsArray Container, class T = typename Container::value_type>
Container::const_iterator binarySearchIter(
    const Container &data,
    const T &value,
    typename Container::const_iterator beginIt = typename Container::iterator{},
    typename Container::const_iterator endIt = typename Container::iterator{})
{
	if (data.begin() == data.end()) {
		return data.end();
	}
	if (beginIt == typename Container::iterator{} && endIt == typename Container::iterator{}) {
		beginIt = data.begin();
		endIt = --data.end();
	}
	while (beginIt <= endIt) {
		auto midIt = beginIt + std::distance(beginIt, endIt) / 2;

		if (*midIt < value) {
			beginIt = ++midIt;
		} else if (*midIt > value) {
			endIt = --midIt;
		} else {
			return midIt;
		}
	}

	return data.end();
}
