#ifndef NODE
#define NODE

template <class T>
struct Node
{
private:
	T* m_data;
	Node<T>* next;
	Node<T>* previous;
	
public:
	Node<T>(T& data)
	{
		m_data = new T();
		memcpy(m_data, &data, sizeof(T));
		next = nullptr;
		previous = nullptr;
	}

	~Node<T>(void)
	{
		m_data = nullptr;
		m_data = 0;
	}

	T& operator = (T& other)
	{
		memcpy(m_data, other.Data(), sizeof(T));
		next = other.Next();
		previous = other.Previous();
		return other;
	}

	T* Data(void) {	return m_data; }
	Node<T>* Next(void) { return next; }
	Node<T>* Previous(void) { return previous; }
	
	void SetNext(Node<T>* data) { next = data; }
	void SetPrevious(Node<T>* data) { previous = data; ;
	}
};

#endif