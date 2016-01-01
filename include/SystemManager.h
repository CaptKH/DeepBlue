#ifndef SYSTEM_MANAGER
#define SYSTEM_MANAGER

#include <vector>

#include "Singleton.h"
#include "System.h"

class SystemManager : public Singleton<SystemManager>
{
private:
	std::vector<System*> systems;

public:
	SystemManager(void);
	~SystemManager(void);

	std::vector<System*> GetSystems(void);
	void AddSystem(System* s);

	void Update(float dt, float tt);
};

#endif