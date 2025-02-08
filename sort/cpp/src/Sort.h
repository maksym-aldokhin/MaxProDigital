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

template<std::bidirectional_iterator InputIt>
void selectionSort(
    const InputIt &begin, const InputIt &end, Direction direction = Direction::SmallToLarge)
{
	if (begin == end) {
		return;
	}

	using ValueType = typename std::iter_value_t<InputIt>;
	std::function<bool(const ValueType &, const ValueType &)> comparator;
	if (direction == Direction::SmallToLarge) {
		comparator = [&direction](const auto &first, const auto &second) {
			return first < second;
		};
	} else {
		comparator = [&direction](const auto &first, const auto &second) {
			return first > second;
		};
	}

	for (auto toSwapIt = begin; toSwapIt != std::prev(end); ++toSwapIt) {
		auto fromSwapIt = toSwapIt;
		for (auto it = std::next(toSwapIt); it != end; ++it) {
			if (comparator(*it, *fromSwapIt)) {
				fromSwapIt = it;
			}
		}
		private_sort::swap(fromSwapIt, toSwapIt);
	}
}

template<typename Container>
    requires std::bidirectional_iterator<typename Container::iterator>
void selectionSort(Container &container, Direction direction = Direction::SmallToLarge)
{
	selectionSort(container.begin(), container.end(), direction);
}

template<std::bidirectional_iterator InputIt>
void insertionSort(
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

	for (auto it = std::next(begin); it != end; ++it) {
		const auto value = *it;
		InputIt itToInsert = it;
		for (; itToInsert != begin; --itToInsert) {
			const auto prewIt = std::prev(itToInsert);
			if (comparator(*prewIt, value)) {
				*itToInsert = *prewIt;
			} else {
				break;
			}
		}
		*itToInsert = value;
	}
}

template<typename Container>
    requires std::bidirectional_iterator<typename Container::iterator>
void insertionSort(Container &container, Direction direction = Direction::SmallToLarge)
{
	insertionSort(container.begin(), container.end(), direction);
}

} // namespace sort
