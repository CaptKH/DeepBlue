#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

#include <vector>



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
	Entity* Get(std::string tag);
	void    Destroy(Entity* e);
	void    Cleanup(void);

	/* Component Functions */
	bool AddComponent(Entity* e, Component* c);
	bool RemoveComponent(Entity* e, ComponentType t);
	std::vector<Entity*> EntitiesWithComponents(ComponentType types, ...);

	template <class T>
	T* GetComponent(Entity* e, ComponentType t)
	{
		Entity* inList = *entities->Get(e);
		if(inList) {
			return dynamic_cast<T*>(inList->GetComponents()->GetComponent(t));
		}
		return nullptr;
	}
};

#endif