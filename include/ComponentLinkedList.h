#ifndef COMPONENT_LINKED_LIST
#define COMPONENT_LINKED_LIST

#include "LinkedList.h"
#include "Component.h"

struct ComponentLinkedList : public LinkedList<Component*>
{
	ComponentLinkedList(void)
	{
		count = 0;
		first = nullptr;
		last = nullptr;
	}

	Component* GetComponent(ComponentType t)
	{
		if (first) {
			Node<Component*>* reset = first;
			Component* c;
			while (first) {
				c = *first->Data();
				if (c->GetType() == t) {
					first = reset;
					return c;
				}
				first = first->Next();
			}
			first = reset;
		}

		return nullptr;
	}

	bool RemoveComponent(ComponentType t) {
		if (first) {
			Node<Component*>* reset = first;
			Component* c;
			while (first) {
				c = *first->Data();
				if (c->GetType() == t) {
					first = reset;
					Remove(c);
					return true;
				}
				first = first->Next();
			}
			first = reset;
		}
		return false;
	}

	bool Contains(ComponentType t)
	{
		if (first) {
			Node<Component*>* reset = first;
			while (first) {
				Component* c = *first->Data();
				if (c->GetType() == t) {
					first = reset;
					return true;
				}
				first = first->Next();
			}
			first = reset;
		}
		return false;
	}
};

#endif