#ifndef MESH
#define MESH

#include "GLEW\glew.h"
#include "GLM\glm.hpp"

#include <stdlib.h>
#include <string>
#include <vector>
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

	glm::vec3 origin;

public:
	Mesh(std::string objFileName);
	Mesh(std::string objFileName, glm::vec3 o);
	Mesh(Vertex* verts, unsigned numVerts, int* inds, unsigned numInds, glm::vec3 o);
	~Mesh(void);

	// Accessors
	GLuint    GetVAO(void)		  { return vao;			}
	GLuint    GetVBO(void)		  { return vbo;			}
	GLuint    GetEBO(void)		  { return ebo;			}
	Vertex*   Vertices(void)	  { return vertices;	}
	int*      Indices(void)		  { return indices;		}
	unsigned  NumVertices(void)   { return numVertices; }
	unsigned  NumIndicies(void)	  { return numIndices;	}
	glm::vec3 Origin(void)		  { return origin;	    }

private:
	void LoadOBJ(std::string filePath, std::vector<Vertex>& objVertices, std::vector<int>& objIndices);
	void GenerateBuffers(void);

};

#endif