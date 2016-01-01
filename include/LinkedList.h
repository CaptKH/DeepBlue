#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

#include "Node.h"

template <class T>
struct LinkedList
{
protected:
	unsigned count;
	Node<T>* first;
	Node<T>* last;

public:
	LinkedList<T>(void)
	{
		count = 0;
		first = nullptr;
		last = nullptr;
	}

	~LinkedList(void)
	{
		Clear();
	}

	unsigned Count(void)
	{
		return count;
	}

	Node<T>* First(void)
	{
		return first;
	}

	Node<T>* Last(void)
	{
		return last;
	}

	T* Add(T* data)
	{
		count++;

		// >= 2 Nodes
		if (last) {
			last->SetNext(new Node<T>(*data));
			last->Next()->SetPrevious(last);
			last = last->Next();
			
		}
		// == 1 Node
		else if (first) {
			last = new Node<T>(*data);
			first->SetNext(last);
			last->SetPrevious(first);
		}
		// Empty list
		else {
			first = new Node<T>(*data);
		}

		return data;
	}

	T* Remove(T& data)
	{
		// First node removal
		if (*first->Data() == data) {
			// == 1 Node
			if (!last) {
				first->~Node();
				first = nullptr;
			}
			// == 2 Nodes
			else if (first->Next() == last) {
				first = last;
				first->Previous()->~Node();
				first->Previous()->SetNext(nullptr);
				first->SetPrevious(nullptr);
				last = nullptr;
			}
			// > 2 Nodes
			else {
				first = first->Next();
				first->Previous()->~Node();
				first->Previous()->SetNext(nullptr);
				first->SetPrevious(nullptr);
			}
			count--;
		}
		// Last node removal
		else if (last && *last->Data() == data) {
			// == 2 Nodes
			if (first->Next() == last) {
				last = nullptr;
				first->Next()->~Node();
				first->Next()->SetPrevious(nullptr);
				first->SetNext(nullptr);
			}
			// > 2 nodes
			else {
				last = last->Previous();
				last->Next()->~Node();
				last->Next()->SetPrevious(nullptr);
				last->SetNext(nullptr);
			}
			count--;
		}
		// Somewhere in the middle...
		else {
			Node<T>* reset = first;
			first = first->Next();
			while (first != last) {
				if (*first->Data() == data) {
					first->Previous()->SetNext(first->Next());
					first->Next()->SetPrevious(first->Previous());
					first->~Node();
					first->SetNext(nullptr);
					first->SetPrevious(nullptr);
					first = reset;
					count--;
					break;
				}
				first = first->Next();
			}

			first = reset;
		}

		return &data;
	}

	T* Get(T& data)
	{
		if (first) {
			Node<T>* reset = first;
			while (first) {
				if (*first->Data() == data) {
					first = reset;
					return first->Data();
				}
				first = first->Next();
			}
			first = reset;
		}
		return nullptr;
	}

	virtual bool Contains(T& data)
	{
		if (first) {
			Node<T>* reset = first;
			while (first) {
				if (*first->Data() == data) {
					first = reset;
					return true;
				}
				first = first->Next();
			}
			first = reset;
		}

		return false;
	}

	void Clear(void)
	{
		count = 0;

		if (first) {
			Node<T>* reset = first->Next();
			first->~Node();
			first->SetNext(nullptr);
			first = nullptr;
			first = reset;

			while (first) {
				first->~Node();
				first = first->Next();
				if (first) {
					first->Previous()->SetNext(nullptr);
					first->SetPrevious(nullptr);
				}
			}

			last = nullptr;
		}
	}

	void Print(void)
	{
		std::cout << "Linked List Print:" << std::endl;

		Node<T>* reset = first;
		while(first) {
			std::cout << "Data: " << *first->Data() << std::endl;
			first = first->Next();
		}
		first = reset;
	}
};

#endif