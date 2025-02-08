#pragma once

#include <functional>
#include <iterator>

namespace sort {

enum class Direction
{
	SmallToLarge,
	LargeToSmall,
};

namespace private_sort {

template<std::input_iterator InputIt>
void swap(const InputIt &first, const InputIt &second)
{
	auto temp = *first;
	*first = *second;
	*second = temp;
}

} // namespace private_sort

template<std::bidirectional_iterator InputIt>
void bubbleSort(
    const InputIt &begin, const InputIt &end, Direction direction = Direction::SmallToLarge)
{
	if (begin == end) {
		return;
	}

	using ValueType = typename std::iter_value_t<InputIt>;
	std::function<bool(const ValueType &, const ValueType &)> comparator;
	if (direction == Direction::SmallToLarge) {
		comparator = [&direction](const auto &first, const auto &second) {
			return first > second;
		};
	} else {
		comparator = [&direction](const auto &first, const auto &second) {
			return first < second;
		};
	}

	bool isSorted;
	auto itEnd = std::prev(end);
	for (auto fIt = begin; fIt != prev(end); ++fIt) {
		isSorted = true;

		for (auto it = begin; it != itEnd; ++it) {
			if (comparator(*it, *std::next(it))) {
				private_sort::swap(it, std::next(it));
				isSorted = false;
			}
		}

		if (isSorted) [[unlikely]] {
			break;
		}
		itEnd = std::prev(itEnd);
	}
}

template<typename Container>
    requires std::bidirectional_iterator<typename Container::iterator>
void bubbleSort(Container &container, Direction direction = Direction::SmallToLarge)
{
	bubbleSort(container.begin(), container.end(), direction);
}

} // namespace sort
