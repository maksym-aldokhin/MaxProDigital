#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <vector>

#include "Search.h"

TEST(LinerSearch, FinedVector)
{
	std::vector<int> vector{1, 9, 5, 7, 3};
	EXPECT_EQ(linerSearchIndex(vector.begin(), vector.end(), 5), 2);
	EXPECT_EQ(linerSearch(vector.begin(), vector.end(), 5), vector.begin() + 2);
}

TEST(LinerSearch, FinedList)
{
	std::list<int> list{1, 9, 5, 7, 3};
	EXPECT_EQ(linerSearchIndex(list.begin(), list.end(), 5), 2);

	auto expectedIt = list.begin();
	++expectedIt;
	++expectedIt;
	EXPECT_EQ(linerSearch(list.begin(), list.end(), 5), expectedIt);
}

TEST(LinerSearch, FinedDeque)
{
	std::deque<int> deque{1, 9, 5, 7, 3};
	EXPECT_EQ(linerSearchIndex(deque.begin(), deque.end(), 5), 2);

	auto expectedIt = deque.begin();
	++expectedIt;
	++expectedIt;
	EXPECT_EQ(linerSearch(deque.begin(), deque.end(), 5), expectedIt);
}

TEST(LinerSearch, UndefinedVector)
{
	std::vector<int> vector{1, 9, 5, 7, 3};
	EXPECT_EQ(linerSearchIndex(vector.begin(), vector.end(), 50), -1);
	EXPECT_EQ(linerSearch(vector.begin(), vector.end(), 50), vector.end());
}

TEST(LinerSearch, UndefinedList)
{
	std::list<int> list{1, 9, 5, 7, 3};
	EXPECT_EQ(linerSearchIndex(list.begin(), list.end(), 50), -1);
	EXPECT_EQ(linerSearch(list.begin(), list.end(), 50), list.end());
}

TEST(LinerSearch, UndefinedDeque)
{
	std::deque<int> deque{1, 9, 5, 7, 3};
	EXPECT_EQ(linerSearchIndex(deque.begin(), deque.end(), 50), -1);
	EXPECT_EQ(linerSearch(deque.begin(), deque.end(), 50), deque.end());
}

TEST(SentinelSearch, FinedVector)
{
	std::vector<int> vector{1, 9, 5, 7, 3};
	EXPECT_EQ(sentinelSearchIndex(vector, 5), 2);
}

TEST(SentinelSearch, FinedList)
{
	std::list<int> list{1, 9, 5, 7, 3};
	EXPECT_EQ(sentinelSearchIndex(list, 5), 2);
}

TEST(SentinelSearch, FinedDeque)
{
	std::deque<int> deque{1, 9, 5, 7, 3};
	EXPECT_EQ(sentinelSearchIndex(deque, 5), 2);
}

TEST(SentinelSearch, UndefinedVector)
{
	std::vector<int> vector{1, 9, 5, 7, 3};
	EXPECT_EQ(sentinelSearchIndex(vector, 50), -1);
}

TEST(SentinelSearch, UndefinedList)
{
	std::list<int> list{1, 9, 5, 7, 3};
	EXPECT_EQ(sentinelSearchIndex(list, 50), -1);
}

TEST(SentinelSearch, UndefinedDeque)
{
	std::deque<int> deque{1, 9, 5, 7, 3};
	EXPECT_EQ(sentinelSearchIndex(deque, 50), -1);
}
