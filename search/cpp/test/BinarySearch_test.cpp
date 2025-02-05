#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <vector>

#include "Search.h"

TEST(BinaryRecursiveIndexSearch, FinedVectorEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16, 17};
	EXPECT_EQ(binarySearchRecursiveIndex(vector, 7), 9);
}

TEST(BinaryRecursiveIndexSearch, UndefinedVectorEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16, 17};
	EXPECT_EQ(binarySearchRecursiveIndex(vector, -15), -1);
}

TEST(BinaryRecursiveIndexSearch, FinedVectorNoEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	EXPECT_EQ(binarySearchRecursiveIndex(vector, 7), 9);
}

TEST(BinaryRecursiveIndexSearch, UndefinedVectorNoEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	EXPECT_EQ(binarySearchRecursiveIndex(vector, -15), -1);
}

TEST(BinaryRecursiveIndexSearch, UndefinedVectorEmpty)
{
	std::vector<int> vector{};
	EXPECT_EQ(binarySearchRecursiveIndex(vector, 0), -1);
}

TEST(BinaryRecursiveIndexSearch, UndefinedVector)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	for (int i = 0; i < vector.size(); ++i) {
		EXPECT_EQ(binarySearchRecursiveIndex(vector, vector[i]), i);
	}
}

TEST(BinaryRecursiveIteratorSearch, FinedVectorEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16, 17};
	EXPECT_EQ(binarySearchRecursive(vector, 7), vector.begin() + 9);
}

TEST(BinaryRecursiveIteratorSearch, UndefinedVectorEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16, 17};
	EXPECT_EQ(binarySearchRecursive(vector, -15), vector.end());
}

TEST(BinaryRecursiveIteratorSearch, FinedVectorNoEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	EXPECT_EQ(binarySearchRecursive(vector, 7), vector.begin() + 9);
}

TEST(BinaryRecursiveIteratorSearch, UndefinedVectorNoEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	EXPECT_EQ(binarySearchRecursive(vector, -15), vector.end());
}

TEST(BinaryRecursiveIteratorSearch, UndefinedVector)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	for (auto it = vector.begin(); it != vector.end(); ++it) {
		EXPECT_EQ(binarySearchRecursive(vector, *it), it);
	}
}

TEST(BinaryRecursiveIteratorSearch, UndefinedVectorEmpty)
{
	std::vector<int> vector{};
	EXPECT_EQ(binarySearchRecursive(vector, 0), vector.end());
}

TEST(BinaryIterIndexSearch, FinedVectorEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16, 17};
	EXPECT_EQ(binarySearchIterIndex(vector, 7), 9);
}

TEST(BinaryIterIndexSearch, UndefinedVectorEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16, 17};
	EXPECT_EQ(binarySearchIterIndex(vector, -15), -1);
}

TEST(BinaryIterIndexSearch, FinedVectorNoEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	EXPECT_EQ(binarySearchIterIndex(vector, 7), 9);
}

TEST(BinaryIterIndexSearch, UndefinedVectorNoEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	EXPECT_EQ(binarySearchIterIndex(vector, -15), -1);
}

TEST(BinaryIterIndexSearch, UndefinedVectorEmpty)
{
	std::vector<int> vector{};
	EXPECT_EQ(binarySearchIterIndex(vector, 0), -1);
}

TEST(BinaryIterIndexSearch, UndefinedVector)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	for (int i = 0; i < vector.size(); ++i) {
		EXPECT_EQ(binarySearchIterIndex(vector, vector[i]), i);
	}
}

TEST(BinaryIterIteratorSearch, FinedVectorEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16, 17};
	EXPECT_EQ(binarySearchIter(vector, 7), vector.begin() + 9);
}

TEST(BinaryIterIteratorSearch, UndefinedVectorEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16, 17};
	EXPECT_EQ(binarySearchIter(vector, -15), vector.end());
}

TEST(BinaryIterIteratorSearch, FinedVectorNoEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	EXPECT_EQ(binarySearchIter(vector, 7), vector.begin() + 9);
}

TEST(BinaryIterIteratorSearch, UndefinedVectorNoEvenSize)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	EXPECT_EQ(binarySearchIter(vector, -15), vector.end());
}

TEST(BinaryIterIteratorSearch, UndefinedVector)
{
	std::vector<int> vector{-19, -18, -17, -16, -14, 0, 1, 2, 4, 7, 10, 13, 16};
	for (auto it = vector.begin(); it != vector.end(); ++it) {
		EXPECT_EQ(binarySearchIter(vector, *it), it);
	}
}

TEST(BinaryIterIteratorSearch, UndefinedVectorEmpty)
{
	std::vector<int> vector{};
	EXPECT_EQ(binarySearchIter(vector, 0), vector.end());
}
