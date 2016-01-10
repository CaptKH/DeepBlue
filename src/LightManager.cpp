#include <LightManager.h>

LightManager::LightManager(void)
{
	lights = std::vector<Entity*>();
}

LightManager::~LightManager(void)
{
}

void LightManager::UpdateLights(std::vector<Entity*>& l)
{
	lights = l;
}