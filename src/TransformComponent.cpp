#include <TransformComponent.h>
#include <GLM/gtc/matrix_transform.hpp>

TransformComponent::TransformComponent(void)
{
	type = ComponentType::TRANSFORM;
	translation = glm::vec3();
	rotation = glm::vec3();
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

TransformComponent::TransformComponent(glm::vec3 t, glm::vec3 r, glm::vec3 s)
	: translation(t), rotation(r), scale(s)
{
	type = ComponentType::TRANSFORM;
}

TransformComponent::~TransformComponent(void)
{
}

glm::mat4 TransformComponent::Transformation(void)
{
	glm::mat4 translationMat;
	translationMat = glm::translate(translationMat, translation);
	glm::mat4 rotationXMat;
	rotationXMat = glm::rotate(rotationXMat, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotationYMat;
	rotationYMat = glm::rotate(rotationYMat, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotationZMat;
	rotationZMat = glm::rotate(rotationZMat, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 scaleMat;
	scaleMat = glm::scale(scaleMat, scale);

	return translationMat * rotationXMat * rotationYMat * rotationZMat * scaleMat;
}

void TransformComponent::Translate(float x, float y, float z) 
{
	translation.x += x;
	translation.y += y;
	translation.z += z;
}

void TransformComponent::Translate(glm::vec3 t)
{
	translation += t;
}

void TransformComponent::Rotate(float x, float y, float z, float degrees)
{
	rotation.x += x * degrees;
	rotation.y += y * degrees;
	rotation.z += z * degrees;
}

void TransformComponent::Rotate(glm::vec3 r, float degrees)
{
	rotation += (r * degrees);
}