#ifndef VERTEX
#define VERTEX

#include "GLEW\glew.h"

struct Vector2
{
	GLfloat x;
	GLfloat y;
};
struct Vector3
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};
struct Vector4
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
};


struct Vertex
{
	Vertex()
	{
		position.x = 0.0f;
		position.y = 0.0f;
		position.z = 0.0f;
	}

	Vertex(float x, float y, float z)
	{
		position.x = x;
		position.y = y;
		position.z = z;
	}

	Vector3 position;
};

#endif