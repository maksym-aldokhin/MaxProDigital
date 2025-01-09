#include <stdexcept>

template<typename T>
class Queue
{
	struct Node
	{
		T data = {};
		Node *next = nullptr;

		Node(T value)
		    : data(value)
		{
		}
	};

public:
	Queue()
	{
	}

	~Queue()
	{
		while (m_front != nullptr) {
			Node *temp = m_front;
			m_front = m_front->next;
			delete temp;
		}
	}

	bool isEmpty() const
	{
		return m_front == nullptr;
	}

	void enqueue(T value)
	{
		Node *newNode = new Node(value);
		if (m_rear == nullptr) {
			m_front = m_rear = newNode;
		} else {
			m_rear->next = newNode;
			m_rear = newNode;
		}
		m_count++;
	}

	T dequeue()
	{
		if (isEmpty()) {
			throw std::out_of_range("Queue is empty.");
		}
		Node *temp = m_front;
		T value = m_front->data;
		m_front = m_front->next;

		if (isEmpty()) {
			m_rear = nullptr;
		}

		delete temp;
		m_count--;
		return value;
	}

	size_t size() const
	{
		return m_count;
	}

	T head() const
	{
		if (isEmpty()) {
			throw std::out_of_range("Queue is empty.");
		}
		return m_front->data;
	}

private:
	Node *m_front = nullptr;
	Node *m_rear = nullptr;
	size_t m_count = 0;
};
