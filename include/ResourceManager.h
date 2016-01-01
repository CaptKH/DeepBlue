#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include "Singleton.h"

#include <string>
#include <unordered_map>

#include "Mesh.h"
#include "Material.h"
#include "Shader.h"

class ResourceManager : public Singleton<ResourceManager>
{
private:
	std::unordered_map<std::string, Mesh*>     meshes;
	std::unordered_map<std::string, Material*> materials;
	std::unordered_map<std::string, Shader*>   shaders;
	std::unordered_map<std::string, GLuint>    vertexArrayObjects;

public:
	ResourceManager(void);
	~ResourceManager(void);

	// Meshes
	Mesh* GetMesh(std::string id);
	bool  RegisterMesh(std::string id, Mesh* mesh);

	// Materials
	Material* GetMaterial(std::string id);
	bool	  RegisterMaterial(std::string id, Material* mat);

	// Shaders
	Shader* GetShader(std::string id);
	bool    RegisterShader(std::string id, Shader* shader);

	// Vertex Array Objects
	GLuint GetVAO(std::string id);
	bool   RegisterVAO(std::string id, GLuint vao);

	void GenerateMeshes(void);
	void GenerateShaders(void);
	void GenerateMaterials(void);
};

#endif