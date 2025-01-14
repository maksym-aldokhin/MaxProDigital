#include <gtest/gtest.h>

#include <chrono>
#include <deque>

#include "StackFixSize.h"

TEST(StackFixSize, CoreTestsPush1value)
{
	const int expectedValue = 10;

	StackFixSize<int> stack(100);
	stack.push(expectedValue);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), expectedValue);
}

TEST(StackFixSize, CoreTestsPush100value)
{
	StackFixSize<int> stack(100);

	for (int i = 0; i < 100; ++i) {
		stack.push(i);
	}
	EXPECT_EQ(stack.size(), 100);
	EXPECT_EQ(stack.peek(), 99);
}

TEST(StackFixSize, CoreTestsPushOverflow)
{
	StackFixSize<int> stack(1);

	stack.push(0);
	EXPECT_THROW(stack.push(1), std::overflow_error);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), 0);
}

TEST(StackFixSize, CoreTestsPeekEmptyStack)
{
	const int expectedValue = 10;
	StackFixSize<int> stack(1);

	EXPECT_THROW(stack.peek(), std::underflow_error);
	stack.push(expectedValue);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), expectedValue);
}

TEST(StackFixSize, CoreTestsPop)
{
	const int expectedValue = 10;
	StackFixSize<int> stack(1);

	stack.push(expectedValue);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), expectedValue);
	EXPECT_EQ(stack.pop(), expectedValue);
}

TEST(StackFixSize, CoreTestsPopEmptyStack)
{
	const int expectedValue = 10;
	StackFixSize<int> stack(1);

	EXPECT_THROW(stack.pop(), std::underflow_error);
	stack.push(expectedValue);
	EXPECT_EQ(stack.size(), 1);
	EXPECT_EQ(stack.peek(), expectedValue);
	EXPECT_EQ(stack.pop(), expectedValue);
	EXPECT_THROW(stack.pop(), std::underflow_error);
}
