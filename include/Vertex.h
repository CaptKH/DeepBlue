#ifndef VERTEX
#define VERTEX

#include "GLM\glm.hpp"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;

	Vertex()
	{
		position = glm::vec3();
	}

	Vertex(float x, float y, float z, float r, float g, float b)
	{
		position = glm::vec3(x, y, z);
		color = glm::vec3(r, g, b);
	}
};

#endif