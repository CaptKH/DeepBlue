#ifndef MESH
#define MESH

#include "GLEW\glew.h"
#include "GLFW\glfw3.h"

#include <stdlib.h>

#include "Vertex.h"

class Mesh 
{
private:
	GLuint   vbo;
	GLuint   vao;
	Vertex*  vertices;
	unsigned numVertices;

public:
	Mesh(Vertex* verts, unsigned numVerts);
	~Mesh(void);

	// Accessors
	GLuint   GetVBO(void)		  { return vbo; }
	GLuint   GetVAO(void)		  { return vao; }
	Vertex*  GetVertices(void)	  { return vertices;  }
	unsigned GetNumVertices(void) { return numVertices; }
};

#endif