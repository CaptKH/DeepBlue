#ifndef SYSTEM
#define SYSTEM

#include "EntityManager.h"

class System
{
protected:
	EntityManager* eManager;

public:
	System(void);
	~System(void);

	virtual void Update(float dt, float tt);
};

#endif