#include <gtest/gtest.h>

#include <chrono>
#include <deque>

#include "deque.h"

TEST(Deque, CoreTestsEnqueue1value)
{
	Deque<int> deque;
	deque.enqueue(10);
	EXPECT_EQ(deque.size(), 1);
}

TEST(Deque, CoreTestsEnqueueAndDequeue)
{
	Deque<int> deque;
	const int expectedValue = 10;

	deque.enqueue(expectedValue);
	EXPECT_EQ(deque.size(), 1);

	const auto actualValue = deque.dequeue();

	EXPECT_EQ(deque.size(), 0);
	EXPECT_EQ(actualValue, expectedValue);
}

TEST(Deque, PerformanceTestcompareWithSTD)
{
	Deque<int> customDeque;
	std::deque<int> stdDeque;

	const auto enqueueCustomDequeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; ++i) {
		customDeque.enqueue(i);
	}
	const auto enqueueCustomDequeEnd = std::chrono::high_resolution_clock::now();

	const auto enqueueStdDequeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; ++i) {
		stdDeque.push_back(i);
	}
	const auto enqueueStdDequeEnd = std::chrono::high_resolution_clock::now();

	EXPECT_EQ(customDeque.size(), stdDeque.size());
	const auto enqueueCustomDequeDelta = abs(enqueueCustomDequeEnd - enqueueCustomDequeStart);
	const auto enqueueStdDequeDelta = abs(enqueueStdDequeEnd - enqueueStdDequeStart);
	EXPECT_TRUE(enqueueCustomDequeDelta < enqueueStdDequeDelta * 1.1);

	const auto dequeueCustomDequeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; ++i) {
		customDeque.dequeue();
	}
	const auto dequeueCustomDequeEnd = std::chrono::high_resolution_clock::now();

	const auto dequeueStdDequeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; ++i) {
		stdDeque.front();
		stdDeque.pop_front();
	}
	const auto dequeueStdDequeEnd = std::chrono::high_resolution_clock::now();

	EXPECT_EQ(customDeque.size(), stdDeque.size());
	const auto dequeueCustomDequeDelta = abs(dequeueCustomDequeEnd - dequeueCustomDequeStart);
	const auto dequeueStdDequeDelta = abs(dequeueStdDequeEnd - dequeueStdDequeStart);
	std::cout << dequeueCustomDequeDelta << "           " << dequeueStdDequeDelta;
	EXPECT_TRUE(dequeueCustomDequeDelta < dequeueStdDequeDelta * 1.2);
}
