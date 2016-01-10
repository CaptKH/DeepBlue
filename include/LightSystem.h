#ifndef LIGHT_SYSTEM
#define LIGHT_SYSTEM

#include "System.h"
#include "LightManager.h"

class LightSystem : public System
{
private:
	LightManager* lManager;

public:
	LightSystem(void);
	~LightSystem(void);

	virtual void Update(float dt, float tt) override;
};

#endif