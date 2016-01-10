#ifndef LIGHT_MANAGER
#define LIGHT_MANAGER

#include <vector>
#include <Singleton.h>
#include <EntityManager.h>

class LightManager : public Singleton<LightManager>
{
private:
	std::vector<Entity*> lights;

public:
	LightManager(void);
	~LightManager(void);

	void UpdateLights(std::vector<Entity*>& l);
};

#endif