#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER


#include "Singleton.h"
#include "EntityLinkedList.h"

class EntityManager : public Singleton<EntityManager>
{
private:
	unsigned entityCounter;
	EntityLinkedList* entities;

public:
	EntityManager(void);
	~EntityManager(void);

	EntityLinkedList* Entities(void);

	Entity* Create(std::string tag);
	void    Destroy(Entity* e);
	Entity* Get(std::string tag);
	void    Cleanup(void);

	bool AddComponent(Entity* e, Component* c);
	bool RemoveComponent(Entity* e, ComponentType t);
	
	template <class T>
	T* GetComponent(Entity* e, ComponentType t)
	{
		Entity* inList = *entities->Get(e);
		if(inList) {
			return inList->GetComponents()->GetComponent(t);
		}
		return nullptr;
	}
};

#endif