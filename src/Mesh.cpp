#include <Mesh.h>
#include <cstring>

Mesh::Mesh(Vertex* verts, unsigned numVerts)
{
	numVertices = numVerts;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * numVerts, verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh(void)
{
}