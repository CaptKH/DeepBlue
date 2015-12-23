#ifndef MESH
#define MESH

#include "GLEW\glew.h"
#include "GLFW\glfw3.h"

#include "Vertex.h"

class Mesh 
{
private:
	GLuint   vbo;
	Vertex*  vertices;
	unsigned numVertices;

public:
	Mesh(Vertex* verts, unsigned numVerts);

	// Accessors
	GLuint   GetVBO(void)		  { return vbo; }
	Vertex*  GetVertices(void)	  { return vertices; }
	unsigned GetNumVertices(void) { return numVertices; }
};

#endif