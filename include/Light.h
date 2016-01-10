#ifndef __LIGHT
#define __LIGHT

#include <GLM\glm.hpp>

struct Light
{
	glm::vec3 position;
	glm::vec3 color;
	float strength;

	Light(void)
	{
		position = glm::vec3();
		color = glm::vec3();
		strength = 0.5f;
	}
};

#endif