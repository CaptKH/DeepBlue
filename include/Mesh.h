#ifndef MESH
#define MESH

#include "GLEW\glew.h"
//#include "GLFW\glfw3.h"

#include <stdlib.h>
#include <string>
#include "Vertex.h"

class Mesh 
{
private:
	GLuint   vao;
	GLuint   vbo;
	GLuint   ebo;
	Vertex*  vertices;
	int*	 indices;
	unsigned numVertices;
	unsigned numIndices;

public:
	Mesh(std::string objFileName);
	Mesh(Vertex* verts, unsigned numVerts, int* inds, unsigned numInds);
	~Mesh(void);

	// Accessors
	GLuint   GetVAO(void)		  { return vao;			}
	GLuint   GetVBO(void)		  { return vbo;			}
	GLuint   GetEBO(void)		  { return ebo;			}
	Vertex*  Vertices(void)		  { return vertices;	}
	int*     Indices(void)		  { return indices;		}
	unsigned NumVertices(void)    { return numVertices; }
	unsigned NumIndicies(void)	  { return numIndices;	}

};

#endif