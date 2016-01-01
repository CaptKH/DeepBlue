#include <SystemManager.h>

SystemManager::SystemManager(void)
{
	systems = std::vector<System*>();
}

SystemManager::~SystemManager(void)
{
	for (int i = 0; i < systems.size(); i++) {
		systems[i]->~System();
		systems[i] = nullptr;
	}
}

std::vector<System*> SystemManager::GetSystems(void)
{
	return systems;
}

void SystemManager::AddSystem(System* s)
{
	systems.push_back(s);
}

void SystemManager::Update(float dt, float tt)
{
	for (int i = 0; i < systems.size(); i++) {
		systems[i]->Update(dt, tt);
	}
}