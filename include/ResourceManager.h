#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include "Singleton.h"

#include <string>
#include <unordered_map>

#include "Mesh.h"
#include "Material.h"
#include "Shader.h"
#include "Texture.h"
#include "ShaderProgram.h"

class ResourceManager : public Singleton<ResourceManager>
{
private:
	std::unordered_map<std::string, Mesh*>			meshes;
	std::unordered_map<std::string, Material*>		materials;
	std::unordered_map<std::string, Texture*>		textures;
	std::unordered_map<std::string, Shader*>		shaders;
	std::unordered_map<std::string, ShaderProgram*> shaderPrograms;
	std::unordered_map<std::string, GLuint>			vertexArrayObjects;

public:
	ResourceManager(void);
	~ResourceManager(void);

	// Meshes
	Mesh* GetMesh(std::string id);
	bool  RegisterMesh(std::string id, Mesh* mesh);

	// Materials
	Material* GetMaterial(std::string id);
	bool	  RegisterMaterial(std::string id, Material* mat);

	// Textures
	Texture* GetTexture(std::string id);
	bool     RegisterTexture(std::string id, Texture* texure);

	// Shaders
	Shader* GetShader(std::string id);
	bool    RegisterShader(std::string id, Shader* shader);

	// Shader Programs
	ShaderProgram* GetShaderProgram(std::string id);
	bool		   RegisterShaderProgram(std::string id, ShaderProgram* shaderProgram);

	// Vertex Array Objects
	GLuint GetVAO(std::string id);
	bool   RegisterVAO(std::string id, GLuint vao);

private:
	void GenerateShaders(void);
	void GenerateShaderPrograms(void);
	void GenerateTextures(void);
	void GenerateMaterials(void);
	void GenerateMeshes(void);
};

#endif