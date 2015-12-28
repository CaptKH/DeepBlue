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

	void Cleanup(void);
};

#endif