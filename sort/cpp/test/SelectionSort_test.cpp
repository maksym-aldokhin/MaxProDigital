#include <gtest/gtest.h>

#include <list>
#include <vector>

#include <Sort.h>

TEST(SelectionSort, SortEmptyIntVector)
{
	std::vector<int> vector{};
	sort::selectionSort(vector.begin(), vector.end());
	EXPECT_EQ(vector, std::vector<int>{});
}

TEST(SelectionSort, SortEmptyIntList)
{
	std::list<int> list{};
	sort::selectionSort(list.begin(), list.end());
	EXPECT_EQ(list, std::list<int>{});
}

TEST(SelectionSort, SortNoEmptyIntVectorSmallToLarge)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::selectionSort(vector.begin(), vector.end());

	std::vector<int> expected{-10, 0, 3, 10, 55, 88, 99};
	EXPECT_EQ(vector, expected);
}

TEST(SelectionSort, SortNoEmptyIntListSmallToLarge)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::selectionSort(list.begin(), list.end());

	std::list<int> expected{13, 18, 20, 25, 30, 34, 54, 57, 77, 96};
	EXPECT_EQ(list, expected);
}

TEST(SelectionSort, SortNoEmptyIntVectorLargeToSmall)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::selectionSort(vector.begin(), vector.end(), sort::Direction::LargeToSmall);

	std::vector<int> expected{99, 88, 55, 10, 3, 0, -10};
	EXPECT_EQ(vector, expected);
}

TEST(SelectionSort, SortNoEmptyIntListLargeToSmall)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::selectionSort(list.begin(), list.end(), sort::Direction::LargeToSmall);

	std::list<int> expected{96, 77, 57, 54, 34, 30, 25, 20, 18, 13};
	EXPECT_EQ(list, expected);
}

TEST(SelectionSort, SortEmptyIntVectorContainer)
{
	std::vector<int> vector{};
	sort::selectionSort(vector);
	EXPECT_EQ(vector, std::vector<int>{});
}

TEST(SelectionSort, SortEmptyIntListContainer)
{
	std::list<int> list{};
	sort::selectionSort(list);
	EXPECT_EQ(list, std::list<int>{});
}

TEST(SelectionSort, SortNoEmptyIntVectorSmallToLargeContainer)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::selectionSort(vector);

	std::vector<int> expected{-10, 0, 3, 10, 55, 88, 99};
	EXPECT_EQ(vector, expected);
}

TEST(SelectionSort, SortNoEmptyIntListSmallToLargeContainer)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::selectionSort(list);

	std::list<int> expected{13, 18, 20, 25, 30, 34, 54, 57, 77, 96};
	EXPECT_EQ(list, expected);
}

TEST(SelectionSort, SortNoEmptyIntVectorLargeToSmallContainer)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::selectionSort(vector, sort::Direction::LargeToSmall);

	std::vector<int> expected{99, 88, 55, 10, 3, 0, -10};
	EXPECT_EQ(vector, expected);
}

TEST(SelectionSort, SortNoEmptyIntListLargeToSmallContainer)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::selectionSort(list, sort::Direction::LargeToSmall);

	std::list<int> expected{96, 77, 57, 54, 34, 30, 25, 20, 18, 13};
	EXPECT_EQ(list, expected);
}
