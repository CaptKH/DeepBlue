#include <Mesh.h>
#include <cstring>

Mesh::Mesh(Vertex* verts, unsigned numVerts, int* inds, unsigned numInds)
{
	numVertices = numVerts;
	numIndices = numInds;
	
	vertices = (Vertex*)malloc(sizeof(Vertex) * numVerts);
	memcpy(vertices, verts, sizeof(Vertex) * numVerts);

	indices = (int*)malloc(sizeof(int) * numInds);
	memcpy(indices, inds, sizeof(int) * numInds);
	
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	// Vertex data
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * numVerts, vertices, GL_STATIC_DRAW);
	
	// Index data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * numInds, inds, GL_STATIC_DRAW);

	// Attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

Mesh::~Mesh(void)
{
}