#include <EntityManager.h>
#include <cstdarg>

EntityManager::EntityManager(void)
{
	entityCounter = 0;
	entities = new EntityLinkedList();
}

EntityManager::~EntityManager(void)
{
	entities->~EntityLinkedList();
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

Entity* EntityManager::Get(std::string tag)
{
	return entities->GetEntity(tag);
}

void EntityManager::Destroy(Entity* e)
{
	e->IsActive(false);
}

void EntityManager::Cleanup(void)
{
	entities->CleanUp();
}

bool EntityManager::AddComponent(Entity* e, Component* c)
{
	Entity* inList = entities->GetEntity(e->GetTag());

	if (inList && !inList->GetComponents()->Contains(c->GetType())) {
		inList->GetComponents()->Add(&c);
		return true;
	}

	return false;
}

bool EntityManager::RemoveComponent(Entity* e, ComponentType t)
{
	Entity* inList = entities->GetEntity(e->GetTag());

	if (inList) {
		return inList->GetComponents()->RemoveComponent(t);
	}
	return false;
}

std::vector<Entity*> EntityManager::EntitiesWithComponents(ComponentType types, ...)
{
	std::vector<Entity*> toReturn = std::vector<Entity*>();

	if (entities->First()) {
		// First we store the arguments in a vector 
		va_list args;
		va_start(args, types);
		std::vector<ComponentType> cTypes = std::vector<ComponentType>();

		while (types < 100 && types > -1) {
			cTypes.push_back(types);
			types = va_arg(args, ComponentType);
		}

		Entity* e;
		int numComponents = 0;
		Node<Entity*>* tracker = entities->First();

		while (tracker) {
			numComponents = 0;
			e = *tracker->Data();
			for (int i = 0; i < cTypes.size(); i++) {
				if (e->GetComponents()->Contains(cTypes[i])) {
					numComponents++;
				}
			}

			if (numComponents == cTypes.size()) { 
				toReturn.push_back(e);
			}
			tracker = tracker->Next();
		}
	}
	return toReturn;
}