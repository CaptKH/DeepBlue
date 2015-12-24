#ifndef MESH
#define MESH

#include "GLEW\glew.h"
#include "GLFW\glfw3.h"

#include "Vertex.h"

class Mesh 
{
private:
	GLuint   vbo;
	unsigned numVertices;

public:
	Mesh(Vertex* verts, unsigned numVerts);
	~Mesh(void);

	// Accessors
	GLuint   GetVBO(void)		  { return vbo; }
	unsigned GetNumVertices(void) { return numVertices; }
};

#endif