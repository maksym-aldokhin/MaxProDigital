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
