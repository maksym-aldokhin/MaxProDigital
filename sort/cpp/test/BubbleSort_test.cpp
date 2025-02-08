#include <gtest/gtest.h>

#include <list>
#include <vector>

#include <Sort.h>

TEST(BubbleSort, SortEmptyIntVector)
{
	std::vector<int> vector{};
	sort::bubbleSort(vector.begin(), vector.end());
	EXPECT_TRUE(vector == std::vector<int>{});
}

TEST(BubbleSort, SortEmptyIntList)
{
	std::list<int> list{};
	sort::bubbleSort(list.begin(), list.end());
	EXPECT_TRUE(list == std::list<int>{});
}

TEST(BubbleSort, SortNoEmptyIntVectorSmallToLarge)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::bubbleSort(vector.begin(), vector.end());

	std::vector<int> expected{-10, 0, 3, 10, 55, 88, 99};
	EXPECT_TRUE(vector == expected);
}

TEST(BubbleSort, SortNoEmptyIntListSmallToLarge)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::bubbleSort(list.begin(), list.end());

	std::list<int> expected{13, 18, 20, 25, 30, 34, 54, 57, 77, 96};
	EXPECT_TRUE(list == expected);
}

TEST(BubbleSort, SortNoEmptyIntVectorLargeToSmall)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::bubbleSort(vector.begin(), vector.end(), sort::Direction::LargeToSmall);

	std::vector<int> expected{99, 88, 55, 10, 3, 0, -10};
	EXPECT_TRUE(vector == expected);
}

TEST(BubbleSort, SortNoEmptyIntListLargeToSmall)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::bubbleSort(list.begin(), list.end(), sort::Direction::LargeToSmall);

	std::list<int> expected{96, 77, 57, 54, 34, 30, 25, 20, 18, 13};
	EXPECT_TRUE(list == expected);
}

TEST(BubbleSort, SortEmptyIntVectorContainer)
{
	std::vector<int> vector{};
	sort::bubbleSort(vector);
	EXPECT_TRUE(vector == std::vector<int>{});
}

TEST(BubbleSort, SortEmptyIntListContainer)
{
	std::list<int> list{};
	sort::bubbleSort(list);
	EXPECT_TRUE(list == std::list<int>{});
}

TEST(BubbleSort, SortNoEmptyIntVectorSmallToLargeContainer)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::bubbleSort(vector);

	std::vector<int> expected{-10, 0, 3, 10, 55, 88, 99};
	EXPECT_TRUE(vector == expected);
}

TEST(BubbleSort, SortNoEmptyIntListSmallToLargeContainer)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::bubbleSort(list);

	std::list<int> expected{13, 18, 20, 25, 30, 34, 54, 57, 77, 96};
	EXPECT_TRUE(list == expected);
}

TEST(BubbleSort, SortNoEmptyIntVectorLargeToSmallContainer)
{
	std::vector<int> vector{99, 55, 88, 3, -10, 10, 0};
	sort::bubbleSort(vector, sort::Direction::LargeToSmall);

	std::vector<int> expected{99, 88, 55, 10, 3, 0, -10};
	EXPECT_TRUE(vector == expected);
}

TEST(BubbleSort, SortNoEmptyIntListLargeToSmallContainer)
{
	std::list<int> list{34, 20, 13, 96, 77, 57, 54, 30, 25, 18};
	sort::bubbleSort(list, sort::Direction::LargeToSmall);

	std::list<int> expected{96, 77, 57, 54, 34, 30, 25, 20, 18, 13};
	EXPECT_TRUE(list == expected);
}
