#include <EntityManager.h>

EntityManager::EntityManager(void)
{
	entityCounter = 0;
	entities = new EntityLinkedList();
}

EntityManager::~EntityManager(void)
{
	entities->Clear();
	entities = nullptr;
	entities = 0;
}

EntityLinkedList* EntityManager::Entities(void)
{
	return entities;
}

Entity* EntityManager::Create(std::string tag)
{
	entityCounter++;
	Entity* e = new Entity(tag, entityCounter);
	entities->Add(e);

	return e;
}

void EntityManager::Destroy(Entity* e)
{
	e->IsActive(false);
}

void EntityManager::Cleanup(void)
{
	LinkedList<Entity*> toKeep;
	
	if (entities->Count() > 0) {
	}
}