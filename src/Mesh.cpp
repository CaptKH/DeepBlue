#include <Mesh.h>
#include <cstring>

Mesh::Mesh(Vertex* verts, unsigned numVerts)
{
	numVertices = numVerts;
	
	vertices = (Vertex*)malloc(sizeof(Vertex) * numVerts);
	memcpy(vertices, verts, sizeof(Vertex) * numVerts);
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * numVerts, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh(void)
{
}