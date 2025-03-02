#include <gtest/gtest.h>

#include <list>
#include <vector>

#include <Sort.h>

TEST(QuickSort, SortEmptyIntVector)
{
	std::vector<int> vector{};
	sort::quickSort(vector);
	EXPECT_EQ(vector, std::vector<int>{});
}

TEST(QuickSort, SortEmptyIntList)
{
	std::list<int> list{};
	sort::quickSort(list.begin(), list.end());
	EXPECT_EQ(list, std::list<int>{});
}

TEST(QuickSort, SortNoEmptyIntVectorSmallToLarge)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::quickSort(vector.begin(), vector.end());

	std::vector<int> expected{-10, 0, 3, 10, 55, 88, 99};
	EXPECT_EQ(vector, expected);
}

TEST(QuickSort, SortNoEmptyIntListSmallToLarge)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::quickSort(list.begin(), list.end());

	std::list<int> expected{13, 18, 20, 25, 30, 34, 54, 57, 77, 96};
	EXPECT_EQ(list, expected);
}

TEST(QuickSort, SortNoEmptyIntVectorLargeToSmall)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::quickSort(vector.begin(), vector.end(), sort::Direction::LargeToSmall);

	std::vector<int> expected{99, 88, 55, 10, 3, 0, -10};
	EXPECT_EQ(vector, expected);
}

TEST(QuickSort, SortNoEmptyIntListLargeToSmall)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::quickSort(list.begin(), list.end(), sort::Direction::LargeToSmall);

	std::list<int> expected{96, 77, 57, 54, 34, 30, 25, 20, 18, 13};
	EXPECT_EQ(list, expected);
}

TEST(QuickSort, SortEmptyIntVectorContainer)
{
	std::vector<int> vector{};
	sort::quickSort(vector);
	EXPECT_EQ(vector, std::vector<int>{});
}

TEST(QuickSort, SortEmptyIntListContainer)
{
	std::list<int> list{};
	sort::quickSort(list);
	EXPECT_EQ(list, std::list<int>{});
}

TEST(QuickSort, SortNoEmptyIntVectorSmallToLargeContainer)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::quickSort(vector);

	std::vector<int> expected{-10, 0, 3, 10, 55, 88, 99};
	EXPECT_EQ(vector, expected);
}

TEST(QuickSort, SortNoEmptyIntListSmallToLargeContainer)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::quickSort(list);

	std::list<int> expected{13, 18, 20, 25, 30, 34, 54, 57, 77, 96};
	EXPECT_EQ(list, expected);
}

TEST(QuickSort, SortNoEmptyIntVectorLargeToSmallContainer)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::quickSort(vector, sort::Direction::LargeToSmall);

	std::vector<int> expected{99, 88, 55, 10, 3, 0, -10};
	EXPECT_EQ(vector, expected);
}

TEST(QuickSort, SortNoEmptyIntListLargeToSmallContainer)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::quickSort(list, sort::Direction::LargeToSmall);

	std::list<int> expected{96, 77, 57, 54, 34, 30, 25, 20, 18, 13};
	EXPECT_EQ(list, expected);
}

TEST(QuickSort, SortedVectorSmallToLarge)
{
	std::vector<int> vector{-10, 0, 3, 10, 55, 88, 99};
	sort::quickSort(vector.begin(), vector.end());

	std::vector<int> expected{-10, 0, 3, 10, 55, 88, 99};
	EXPECT_EQ(vector, expected);
}

TEST(QuickSort, SortedListSmallToLarge)
{
	std::list<int> list{13, 18, 20, 25, 30, 34, 54, 57, 77, 96};
	sort::quickSort(list.begin(), list.end());

	std::list<int> expected{13, 18, 20, 25, 30, 34, 54, 57, 77, 96};
	EXPECT_EQ(list, expected);
}

TEST(QuickSort, SortedVectorLargeToSmall)
{
	std::vector<int> vector{99, 88, 55, 10, 3, 0, -10};
	sort::quickSort(vector.begin(), vector.end(), sort::Direction::LargeToSmall);

	std::vector<int> expected{99, 88, 55, 10, 3, 0, -10};
	EXPECT_EQ(vector, expected);
}

TEST(QuickSort, SortedListLargeToSmall)
{
	std::list<int> list{96, 77, 57, 54, 34, 30, 25, 20, 18, 13};
	sort::quickSort(list.begin(), list.end(), sort::Direction::LargeToSmall);

	std::list<int> expected{96, 77, 57, 54, 34, 30, 25, 20, 18, 13};
	EXPECT_EQ(list, expected);
}
