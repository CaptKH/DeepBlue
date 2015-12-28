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
	Node<T>(T* data)
		: m_data(data)
	{
		next = nullptr;
		previous = nullptr;
	}

	~Node<T>(void)
	{
		m_data = nullptr;
		m_data = 0;
	}

	T* Data(void) {	return m_data; }
	Node<T>* Next(void) { return next; }
	Node<T>* Previous(void) { return previous; }
	
	void SetNext(Node<T>* data) { next = data; }
	void SetPrevious(Node<T>* data) { previous = data; ;
	}
};

#endif