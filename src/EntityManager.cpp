#include <EntityManager.h>

EntityManager::EntityManager(void)
{
	entities = std::vector<Entity*>();
}

std::vector<Entity*> EntityManager::Entities(void)
{
	return entities;
}

Entity* EntityManager::Create(std::string tag)
{
	for (int i = 0; i < entities.size(); i++)
	{

	}

	return new Entity();
}

void EntityManager::Destroy(Entity* e)
{
	unsigned entityID = e->GetID();
	markedForDestruction.push_back(entityID);
}

void EntityManager::Cleanup(void)
{
}