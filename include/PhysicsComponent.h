#ifndef PHYSICS_COMPONENT
#define PHYSICS_COMPONENT

#include "Component.h"

#include "GLM\glm.hpp"

class PhysicsComponent : public Component
{
private:
	glm::vec3 velocity;
	glm::vec3 acceleration;
	float drag;

public:
	PhysicsComponent(void);
	PhysicsComponent(glm::vec3 v, glm::vec3 a, float d);
	virtual ~PhysicsComponent(void);

	void Update(float dt, float tt, glm::vec3& position);

	glm::vec3 GetVelocity(void);
	glm::vec3 GetAcceleration(void);
	float	  GetDrag(void);

	void Accelerate(glm::vec3 a);
};

#endif
