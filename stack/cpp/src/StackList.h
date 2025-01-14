#include <stdexcept>

template<typename T>
class StackList
{
private:
	struct Node
	{
		T data;
		Node *next;

		Node(T value)
		    : data(value)
		    , next(nullptr)
		{
		}
	};

	Node *m_top;
	size_t m_size;

public:
	StackList()
	    : m_top(nullptr)
	    , m_size{0}
	{
	}

	~StackList()
	{
		while (!isEmpty()) {
			auto temp = m_top;
			m_top = m_top->next;
			delete temp;
		}
	}

	void push(int value)
	{
		Node *newNode = new Node(value);
		newNode->next = m_top;
		m_top = newNode;
		++m_size;
	}

	T pop()
	{
		if (isEmpty()) {
			throw std::underflow_error("Stack underflow");
		}
		T poppedValue = m_top->data;
		Node *temp = m_top;
		m_top = m_top->next;
		delete temp;
		--m_size;
		return poppedValue;
	}

	T peek() const
	{
		if (isEmpty()) {
			throw std::underflow_error("Stack is empty");
		}
		return m_top->data;
	}

	bool isEmpty() const
	{
		return m_top == nullptr;
	}

	size_t size() const
	{
		return m_size;
	}
};
