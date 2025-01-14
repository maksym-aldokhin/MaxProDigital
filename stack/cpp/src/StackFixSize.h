#include <stdexcept>

template<typename T>
class StackFixSize
{
public:
	StackFixSize(T size)
	    : m_size(size)
	    , m_top(-1)
	{
		m_arr = new T[m_size];
	}

	~StackFixSize()
	{
		delete[] m_arr;
	}

	void push(int value)
	{
		if (isFull()) {
			throw std::overflow_error("Stack overflow");
		}
		m_arr[++m_top] = value;
	}

	T pop()
	{
		if (isEmpty()) {
			throw std::underflow_error("Stack underflow");
		}
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
		return m_top == m_size - 1;
	}

	size_t size() const
	{
		return m_top + 1;
	}

private:
	T *m_arr;
	size_t m_size;
	int m_top;
};
