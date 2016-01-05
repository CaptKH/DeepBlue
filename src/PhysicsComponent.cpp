#include <PhysicsComponent.h>

PhysicsComponent::PhysicsComponent(void)
{
	type = ComponentType::PHYSICS;
	velocity = glm::vec3();
	acceleration = glm::vec3();
	drag = 0.975f;
}

PhysicsComponent::PhysicsComponent(glm::vec3 v, glm::vec3 a, float d)
	: velocity(v), acceleration(a), drag(d)
{
	type = ComponentType::PHYSICS;
}

PhysicsComponent::~PhysicsComponent(void)
{
}

void PhysicsComponent::Update(float dt, float tt, glm::vec3& position)
{
	velocity += acceleration;
	position += velocity * dt + acceleration * dt * dt * 0.5f;
	velocity *= drag * dt;
	acceleration *= drag * dt;
}

glm::vec3 PhysicsComponent::GetVelocity(void)
{
	return velocity;
}

glm::vec3 PhysicsComponent::GetAcceleration(void)
{
	return acceleration;
}

float PhysicsComponent::GetDrag(void)
{
	return drag;
}

void PhysicsComponent::Accelerate(glm::vec3 a) 
{
	acceleration += a;
}