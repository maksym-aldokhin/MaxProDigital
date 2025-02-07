#pragma once

#include <stdexcept>

template<typename T>
class StackVectorUnlimited
{
public:
	explicit StackVectorUnlimited()
	    : m_arr(nullptr)
	    , m_top(-1)
	    , m_reserved(0)
	{
	}

	~StackVectorUnlimited()
	{
		delete[] m_arr;
	}

	void push(int value)
	{
		if (isFull()) {
			expand();
		}
		m_arr[++m_top] = value;
	}

	T pop()
	{
		if (isEmpty()) {
			throw std::underflow_error("Stack underflow");
		}

		reduce();
		return m_arr[m_top--];
	}

	T peek() const
	{
		if (isEmpty()) {
			throw std::underflow_error("Stack is empty");
		}
		return m_arr[m_top];
	}

	bool isEmpty() const
	{
		return m_top == -1;
	}

	bool isFull() const
	{
		return m_top == m_reserved - 1;
	}

	size_t size() const
	{
		return m_top + 1;
	}

private:
	void expand()
	{
		if (m_reserved == 0) {
			m_reserved = 10;
		} else {
			m_reserved *= 2;
		}

		auto newArray = new T[m_reserved];
		if (m_arr) {
			copyArray(newArray);
			delete[] m_arr;
		}
		m_arr = newArray;
	}

	void reduce()
	{
		if (m_reserved / 2 > size()) {
			m_reserved /= 2;

			auto newArray = new T[m_reserved];
			if (m_arr) {
				copyArray(newArray);
				delete[] m_arr;
			}
			m_arr = newArray;
		}
	}

	void copyArray(T *newArray)
	{
		for (int i = 0; i < m_top + 1; ++i) {
			newArray[i] = m_arr[i];
		}
	}

	T *m_arr;
	int m_top;
	size_t m_reserved;
};
