#ifndef VERTEX
#define VERTEX

#include "GLM\glm.hpp"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 uv;

	Vertex()
	{
		position = glm::vec3();
		normal	 = glm::vec3();
		color	 = glm::vec3();
		uv		 = glm::vec2();
	}

	Vertex(float x, float y, float z, float xn, float yn, float zn, float r, float g, float b, float u, float v)
	{
		position = glm::vec3(x, y, z);
		normal	 = glm::vec3(xn, yn, zn);
		color	 = glm::vec3(r, g, b);
		uv		 = glm::vec2(u, v);
	}
};

#endif