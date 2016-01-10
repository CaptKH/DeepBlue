#include <LightSystem.h>

#include <TransformComponent.h>
#include <LightComponent.h>

LightSystem::LightSystem(void)
{
	lManager = LightManager::Instance();
}

LightSystem::~LightSystem(void)
{
}

void LightSystem::Update(float dt, float tt)
{
	std::vector<Entity*> hasLightComponent = eManager->EntitiesWithComponents(ComponentType::LIGHT);

	for (Entity* e : hasLightComponent) {
		LightComponent* lComponent = eManager->GetComponent<LightComponent>(e, ComponentType::LIGHT);
		TransformComponent* tComponent = eManager->GetComponent<TransformComponent>(e, ComponentType::TRANSFORM);

		if (tComponent) {
			lComponent->GetLight()->position = lComponent->GetInitialPosition() + tComponent->translation;
		}
	}
}