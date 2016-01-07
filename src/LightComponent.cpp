#include <LightComponent.h>

LightComponent::LightComponent(void)
{
	type = ComponentType::LIGHT;
	light = new Light();
}

LightComponent::LightComponent(Light* l)
{
	type = ComponentType::LIGHT;
	light = new Light();
	memcpy(light, l, sizeof(Light));
}

LightComponent::~LightComponent(void)
{
	delete light;
	light = 0;
}

Light* LightComponent::GetLight(void)
{
	return light;
}