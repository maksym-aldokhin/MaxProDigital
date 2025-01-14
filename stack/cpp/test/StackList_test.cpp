#include <gtest/gtest.h>

#include <chrono>
#include <deque>

#include "StackList.h"

TEST(StackList, CoreTestsPush1value)
{
	const int expectedValue = 10;

	StackList<int> stack;
	stack.push(expectedValue);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), expectedValue);
}

TEST(StackList, CoreTestsPush100value)
{
	StackList<int> stack;

	for (int i = 0; i < 100; ++i) {
		stack.push(i);
	}
	EXPECT_EQ(stack.size(), 100);
	EXPECT_EQ(stack.peek(), 99);
}

TEST(StackList, CoreTestsPeekEmptyStack)
{
	const int expectedValue = 10;
	StackList<int> stack;

	EXPECT_THROW(stack.peek(), std::underflow_error);
	stack.push(expectedValue);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), expectedValue);
}

TEST(StackList, CoreTestsPop)
{
	const int expectedValue = 10;
	StackList<int> stack;

	stack.push(expectedValue);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), expectedValue);
	EXPECT_EQ(stack.pop(), expectedValue);
}

TEST(StackList, CoreTestsPopEmptyStack)
{
	const int expectedValue = 10;
	StackList<int> stack;

	EXPECT_THROW(stack.pop(), std::underflow_error);
	stack.push(expectedValue);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), expectedValue);
	EXPECT_EQ(stack.pop(), expectedValue);
	EXPECT_THROW(stack.pop(), std::underflow_error);
}
