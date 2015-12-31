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
	entities->Add(&e);

	return e;
}

void EntityManager::Destroy(Entity* e)
{
	e->IsActive(false);
}

Entity* EntityManager::Get(std::string tag)
{
	return entities->GetEntity(tag);
}

void EntityManager::Cleanup(void)
{
	entities->CleanUp();
}

bool EntityManager::AddComponent(Entity* e, Component* c)
{
	Entity* inList = *entities->Get(e);

	if (inList && !inList->GetComponents()->Contains(c->GetType())) {
		inList->GetComponents()->Add(&c);
		return true;
	}

	return false;
}

bool EntityManager::RemoveComponent(Entity* e, ComponentType t)
{
	Entity* inList = *entities->Get(e);

	if (inList) {
		return inList->GetComponents()->RemoveComponent(t);
	}
	return false;
}