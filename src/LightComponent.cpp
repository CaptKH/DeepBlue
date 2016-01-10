#include <LightComponent.h>

LightComponent::LightComponent(void)
{
	type = ComponentType::LIGHT;
	light = new Light();
	initialPosition = glm::vec3();
}

LightComponent::LightComponent(Light* l)
{
	type = ComponentType::LIGHT;
	light = new Light();
	memcpy(light, l, sizeof(Light));
	initialPosition = light->position;
}

LightComponent::~LightComponent(void)
{
	delete light;
	light = 0;
}