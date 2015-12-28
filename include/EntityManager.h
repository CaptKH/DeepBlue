#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

#include <vector>

#include "Singleton.h"
#include "Entity.h"

class EntityManager : public Singleton<EntityManager>
{
private:
	std::vector<Entity*> entities;
	std::vector<unsigned> markedForDestruction;

public:
	EntityManager(void);
	~EntityManager(void);

	std::vector<Entity*> Entities(void);

	Entity* Create(std::string tag);
	void    Destroy(Entity* e);

private:
	void Cleanup(void);
};

#endif