#ifndef PHYSICS_SYSTEM
#define PHYSICS_SYSTEM

#include "System.h"

class PhysicsSystem : public System
{
public:
	PhysicsSystem(void);
	~PhysicsSystem(void);

	virtual void Update(float dt, float tt) override;
};

#endif