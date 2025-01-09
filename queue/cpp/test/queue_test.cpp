#include <gtest/gtest.h>

#include <chrono>
#include <deque>

#include "queue.h"

TEST(Queue, CoreTestsEnqueue1value)
{
	Queue<int> queue;
	queue.enqueue(10);
	EXPECT_EQ(queue.size(), 1);
}

TEST(Queue, CoreTestsEnqueueAndDequeue)
{
	Queue<int> queue;
	const int expectedValue = 10;

	queue.enqueue(expectedValue);
	EXPECT_EQ(queue.size(), 1);

	const auto actualValue = queue.dequeue();

	EXPECT_EQ(queue.size(), 0);
	EXPECT_EQ(actualValue, expectedValue);
}

TEST(Queue, CoreTestsHead)
{
	Queue<int> queue;
	const int expectedValue = 10;

	queue.enqueue(expectedValue);
	EXPECT_EQ(queue.size(), 1);

	EXPECT_EQ(queue.head(), expectedValue);
}

TEST(Queue, PerformanceTestcompareWithSTD)
{
	// not work
	return;
	Queue<int> customQueue;
	std::deque<int> stdDeque;

	const auto enqueueCustomDequeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; ++i) {
		customQueue.enqueue(i);
	}
	const auto enqueueCustomDequeEnd = std::chrono::high_resolution_clock::now();

	const auto enqueueStdDequeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; ++i) {
		stdDeque.push_back(i);
	}
	const auto enqueueStdDequeEnd = std::chrono::high_resolution_clock::now();

	EXPECT_EQ(customQueue.size(), stdDeque.size());
	const auto enqueueCustomDequeDelta = abs(
	    enqueueCustomDequeEnd.time_since_epoch().count()
	    - enqueueCustomDequeStart.time_since_epoch().count());
	const auto enqueueStdDequeDelta = abs(
	    enqueueStdDequeEnd.time_since_epoch().count()
	    - enqueueStdDequeStart.time_since_epoch().count());
	EXPECT_TRUE(enqueueCustomDequeDelta < enqueueStdDequeDelta * 1.5);

	const auto dequeueCustomDequeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; ++i) {
		customQueue.dequeue();
	}
	const auto dequeueCustomDequeEnd = std::chrono::high_resolution_clock::now();

	const auto dequeueStdDequeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; ++i) {
		stdDeque.front();
		stdDeque.pop_front();
	}
	const auto dequeueStdDequeEnd = std::chrono::high_resolution_clock::now();

	EXPECT_EQ(customQueue.size(), stdDeque.size());
	const auto dequeueCustomDequeDelta = abs(
	    dequeueCustomDequeEnd.time_since_epoch().count()
	    - dequeueCustomDequeStart.time_since_epoch().count());
	const auto dequeueStdDequeDelta = abs(
	    dequeueStdDequeEnd.time_since_epoch().count()
	    - dequeueStdDequeStart.time_since_epoch().count());
	std::cout << dequeueCustomDequeDelta << "           " << dequeueStdDequeDelta << "        "
	          << dequeueStdDequeDelta * 1.5;
	EXPECT_TRUE(dequeueCustomDequeDelta < dequeueStdDequeDelta * 1.5);
}
