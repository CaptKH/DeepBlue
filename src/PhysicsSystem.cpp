#include <PhysicsSystem.h>
#include <TransformComponent.h>
#include <PhysicsComponent.h>

PhysicsSystem::PhysicsSystem(void)
{
}

PhysicsSystem::~PhysicsSystem(void)
{
}

void PhysicsSystem::Update(float dt, float tt)
{
	std::vector<Entity*> entitiesWithPhysicsComponents = eManager->EntitiesWithComponents(ComponentType::PHYSICS);

	for (auto& e : entitiesWithPhysicsComponents) {
		TransformComponent* tComponent = eManager->GetComponent<TransformComponent>(e, ComponentType::TRANSFORM);
		PhysicsComponent* pComponent = eManager->GetComponent<PhysicsComponent>(e, ComponentType::PHYSICS);

		pComponent->Update(dt, tt, tComponent->translation);
	}
}