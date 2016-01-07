#ifndef LIGHT_MANAGER
#define LIGHT_MANAGER

#include <Singleton.h>

class LightManager : public Singleton<LightManager>
{
public:
	LightManager(void);
	~LightManager(void);
};

#endif