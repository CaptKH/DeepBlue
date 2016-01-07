#include <Mesh.h>
#include <fstream>
#include <iostream>
#include <vector>

Mesh::Mesh(std::string objFileName, Texture* tex)
{
	vertices = new Vertex();
	numVertices = 0;
	indices = new int();
	numIndices = 0;
	origin = glm::vec3();
	texture = tex;

	std::string filePath = "assets/objs/" + objFileName;
	std::vector<Vertex> objVertices;
	std::vector<int> objIndices;
	LoadOBJ(filePath, objVertices, objIndices);

	vertices = &objVertices[0];
	indices = &objIndices[0];

	GenerateBuffers();
}

Mesh::Mesh(std::string objFileName, glm::vec3 o, Texture* tex)
{
	vertices = new Vertex();
	numVertices = 0;
	indices = new int();
	numIndices = 0;
	origin = o;
	texture = tex;

	std::string filePath = "assets/objs/" + objFileName;
	std::vector<Vertex> objVertices;
	std::vector<int> objIndices;
	LoadOBJ(filePath, objVertices, objIndices);

	vertices = &objVertices[0];
	indices = &objIndices[0];

	GenerateBuffers();
}

Mesh::Mesh(Vertex* verts, unsigned numVerts, int* inds, unsigned numInds, glm::vec3 o, Texture* tex)
{
	numVertices = numVerts;
	numIndices = numInds;
	origin = o;
	texture = tex;

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
	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

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
				glm::vec3 position;
				fscanf_s(objFile, "%f %f %f\n", &position.x, &position.y, &position.z);
				positions.push_back(position);
			}
			else if (strcmp(lineHeader, "vt") == 0) {
				glm::vec2 uv;
				fscanf_s(objFile, "%f %f\n", &uv.x, &uv.y);
				uvs.push_back(uv);
			}
			else if (strcmp(lineHeader, "vn") == 0) {
				glm::vec3 normal;
				fscanf_s(objFile, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
				normals.push_back(normal);
			}
			else if (strcmp(lineHeader, "f") == 0) {
				int indices[9];
				int matches = fscanf_s(objFile, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &indices[0], &indices[1], &indices[2], &indices[3], &indices[4], &indices[5], &indices[6], &indices[7], &indices[8]);

				Vertex v1;
				v1.position = positions[indices[0] - 1];
				v1.normal	= normals[indices[2] - 1];
				v1.color    = positions[indices[0] - 1];
				v1.uv		= uvs[indices[1] - 1];

				Vertex v2;
				v2.position = positions[indices[3] - 1];
				v2.normal = normals[indices[5] - 1];
				v2.color = positions[indices[3] - 1];
				v2.uv = uvs[indices[4] - 1];

				Vertex v3;
				v3.position = positions[indices[6] - 1];
				v3.normal = normals[indices[8] - 1];
				v3.color = positions[indices[6] - 1];
				v3.uv = uvs[indices[7] - 1];

				objVertices.push_back(v1);
				objVertices.push_back(v2);
				objVertices.push_back(v3);
				objIndices.push_back(numIndices++);
				objIndices.push_back(numIndices++);
				objIndices.push_back(numIndices++);
				numVertices += 3;
			}
		}
	}
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
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(GLfloat) * 3));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(GLfloat) * 6));
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(GLfloat) * 9));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
}