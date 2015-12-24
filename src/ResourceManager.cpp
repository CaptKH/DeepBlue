#include <ResourceManager.h>

ResourceManager::ResourceManager(void)
{
	meshes = std::unordered_map<std::string, Mesh*>();
}

ResourceManager::~ResourceManager(void)
{
	for (auto i = meshes.begin(); i != meshes.end(); i++) {
		delete i->second;
		i->second = 0;
	}

	for (auto i = shaders.begin(); i != shaders.end(); i++) {
		delete i->second;
		i->second = 0;
	}
}

Mesh* ResourceManager::GetMesh(std::string id)
{
	if (meshes.find(id) == meshes.end())
		return nullptr;
	else
		return meshes.find(id)->second;
}

bool ResourceManager::RegisterMesh(std::string id, Mesh* mesh) 
{
	if (meshes.find(id) != meshes.end())
		return false;
	else
		meshes.emplace(id, mesh);

	return true;
}

Material* ResourceManager::GetMaterial(std::string id)
{
	if (materials.find(id) == materials.end())
		return nullptr;
	else
		return materials.find(id)->second;
}

bool ResourceManager::RegisterMaterial(std::string id, Material* mat)
{
	if (materials.find(id) != materials.end())
		return false;
	else
		materials.emplace(id, mat);
	
	return true;
}

Shader* ResourceManager::GetShader(std::string id)
{
	if (shaders.find(id) == shaders.end())
		return nullptr;
	else
		return shaders.find(id)->second;
}

bool ResourceManager::RegisterShader(std::string id, Shader* shader)
{
	if (shaders.find(id) != shaders.end())
		return false;
	else
		shaders.emplace(id, shader);

	return true;
}

void ResourceManager::GenerateMeshes(void) 
{
	GLuint triangleVBO;
	Vertex triangleVerts[] =
	{
		Vertex(-0.5f, -0.5f, 0.0f),
		Vertex( 0.5f, -0.5f, 0.0f),
		Vertex( 0.0f,  0.5f, 0.0f)
	};

	Mesh* triangleMesh = new Mesh(triangleVerts, 3);
	RegisterMesh("Triangle", triangleMesh);
}

void ResourceManager::GenerateShaders(void)
{
	Shader* standardVS = new Shader("StandardVS.glsl", ShaderType::VERTEXSHADER);
	RegisterShader("standardVS", standardVS);

	Shader* standardFS = new Shader("StandardFS.glsl", ShaderType::FRAGMENTSHADER);
	RegisterShader("StandardFS", standardFS);
}