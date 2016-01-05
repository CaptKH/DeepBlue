#include <Mesh.h>
#include <fstream>
#include <iostream>
#include <vector>

Mesh::Mesh(std::string objFileName)
{
	vertices = new Vertex();
	numVertices = 0;
	indices = new int();
	numIndices = 0;
	origin = glm::vec3();

	std::string filePath = "assets/objs/" + objFileName;
	std::vector<Vertex> objVertices;
	std::vector<int> objIndices;
	LoadOBJ(filePath, objVertices, objIndices);

	vertices = &objVertices[0];
	indices = &objIndices[0];

	GenerateBuffers();
}

Mesh::Mesh(std::string objFileName, glm::vec3 o)
{
	vertices = new Vertex();
	numVertices = 0;
	indices = new int();
	numIndices = 0;
	origin = o;

	std::string filePath = "assets/objs/" + objFileName;
	std::vector<Vertex> objVertices;
	std::vector<int> objIndices;
	LoadOBJ(filePath, objVertices, objIndices);

	vertices = &objVertices[0];
	indices = &objIndices[0];

	GenerateBuffers();
}

Mesh::Mesh(Vertex* verts, unsigned numVerts, int* inds, unsigned numInds, glm::vec3 o)
{
	numVertices = numVerts;
	numIndices = numInds;
	origin = o;

	vertices = (Vertex*)malloc(sizeof(Vertex) * numVerts);
	memcpy(vertices, verts, sizeof(Vertex) * numVerts);

	indices = (int*)malloc(sizeof(int) * numInds);
	memcpy(indices, inds, sizeof(int) * numInds);

	GenerateBuffers();
}

Mesh::~Mesh(void)
{
}

void Mesh::LoadOBJ(std::string filePath, std::vector<Vertex>& objVertices, std::vector<int>& objIndices) 
{
	FILE* objFile;
	fopen_s(&objFile, filePath.c_str(), "r");
	if (objFile != NULL) {
		while (1) {
			char lineHeader[128];
			// Read first word of first line
			int res = fscanf_s(objFile, "%s", lineHeader, sizeof(char) * 128);
			// Exit if end of file
			if (res == EOF) break;

			// Process vertices
			if (strcmp(lineHeader, "v") == 0) {
				Vertex v = Vertex();
				fscanf_s(objFile, "%f %f %f\n", &v.position.x, &v.position.y, &v.position.z);
				v.color = v.position;
				objVertices.push_back(v);
				numVertices++;
			}
			else if (strcmp(lineHeader, "f") == 0) {
				int vertInds[3], uvInds[3], normalInds[3];
				int matches = fscanf_s(objFile, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertInds[0], &uvInds[0], &normalInds[0], &vertInds[1], &uvInds[1], &normalInds[1], &vertInds[2], &uvInds[2], &normalInds[2]);

				objIndices.push_back(vertInds[0] - 1);
				objIndices.push_back(vertInds[1] - 1);
				objIndices.push_back(vertInds[2] - 1);
				numIndices += 3;
			}
		}
	}

	vertices = &objVertices[0];
	indices = &objIndices[0];
}

void Mesh::GenerateBuffers(void)
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	// Vertex data
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * numVertices, vertices, GL_STATIC_DRAW);

	// Index data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * numIndices, indices, GL_STATIC_DRAW);

	// Attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(glm::vec3)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}