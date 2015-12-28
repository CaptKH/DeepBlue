#ifndef ENTITY_LINKED_LIST
#define ENTITY_LINKED_LIST

#include "LinkedList.h"
#include "Entity.h"

struct EntityLinkedList : public LinkedList<Entity*>
{
public:
	EntityLinkedList(void)
	{
		count = 0;
		first = nullptr;
		last = nullptr;
	}

	void CleanUp(void)
	{
		if (first) {
			Entity* e = *first->Data();

			// Take care of any at the beginning
			while (!e->IsActive() && first) {
				Remove(e);
				if (first) e = *first->Data();
			}

			if (first) {
				Node<Entity*>* reset = first;
				while (reset->Next()) {
					e = *reset->Next()->Data();
					if (!e->IsActive()) {
						Remove(e);
					}
					else if(reset) reset = reset->Next();
				}
			}

		}

	}
};


#endif
