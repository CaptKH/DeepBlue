#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT

#include "Component.h"

#include "GLM/glm.hpp"

class TransformComponent : public Component
{
private:
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;

public:
	TransformComponent(void);
	TransformComponent(glm::vec3 t, glm::vec3 r, glm::vec3 s);
	virtual ~TransformComponent(void);

	glm::mat4 Transformation(void);

	void Translate(float x, float y, float z);
	void Translate(glm::vec3 t);

	void Rotate(float x, float y, float z, float degrees);
	void Rotate(glm::vec3 r, float degrees);
};

#endif