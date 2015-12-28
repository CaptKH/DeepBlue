#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

#include "Node.h"

template <class T>
struct LinkedList
{
private:
	Node<T>* first;
	Node<T>* last;

public:
	LinkedList<T>(void)
	{
		first = nullptr;
		last = nullptr;
	}

	~LinkedList(void)
	{
		Clear();
	}

	T* Add(T* data)
	{
		Node<T>* toAdd = new Node<T>(data);

		// >= 2 Nodes
		if (last) {
			toAdd->SetPrevious(last);
			last->SetNext(toAdd);
			last = last->Next();
		}
		// == 1 Node
		else if (first) {
			last = toAdd;
			first->SetNext(last);
			last->SetPrevious(first);
		}
		// Empty list
		else {
			first = toAdd;
		}

		return data;
	}

	T* Remove(T* data)
	{
		// First node removal
		if (*first->Data() == *data) {
			// == 1 Node
			if (!last) {
				first->~Node();
				first = nullptr;
			}
			// == 2 Nodes
			else if(first->Next() == last) {
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
		}
		// Last node removal
		else if (last && *last->Data() == *data) {
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
		}
		// Somewhere in the middle...
		else {
			Node<T>* reset = first;
			first = first->Next();
			while (first != last) {
				if (*first->Data() == *data) {
					first->Previous()->SetNext(first->Next());
					first->Next()->SetPrevious(first->Previous());
					first->~Node();
					first->SetNext(nullptr);
					first->SetPrevious(nullptr);
					first = nullptr;
					break;
				}
				first = first->Next();
			}

			first = reset;
		}

		return data;
	}

	void Clear(void)
	{
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