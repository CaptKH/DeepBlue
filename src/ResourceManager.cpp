#include <ResourceManager.h>

ResourceManager::ResourceManager(void)
{
	meshes = std::unordered_map<std::string, Mesh*>();
	materials = std::unordered_map<std::string, Material*>();
	shaders = std::unordered_map<std::string, Shader*>();

	GenerateMeshes();
	GenerateShaders();
	GenerateMaterials();
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

GLuint ResourceManager::GetVAO(std::string id) 
{
	if (vertexArrayObjects.find(id) == vertexArrayObjects.end())
		return 0;
	else
		return vertexArrayObjects.find(id)->second;
}

bool ResourceManager::RegisterVAO(std::string id, GLuint vao)
{
	if (vertexArrayObjects.find(id) != vertexArrayObjects.end())
		return false;
	else
		vertexArrayObjects.emplace(id, vao);

	return true;
}

void ResourceManager::GenerateShaders(void)
{
	Shader* standardVS = new Shader("StandardVS.glsl", ShaderType::VERTEXSHADER);
	RegisterShader("StandardVS", standardVS);

	Shader* standardFS = new Shader("StandardFS.glsl", ShaderType::FRAGMENTSHADER);
	RegisterShader("StandardFS", standardFS);
}

void ResourceManager::GenerateMeshes(void)
{
	GLuint triangleVBO;
	Vertex triangleVerts[] =
	{
		Vertex(-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f),
		Vertex( 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f),
		Vertex( 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f)
	};

	int triangleIndices[] = { 0, 1, 2 };

	Mesh* triangleMesh = new Mesh(triangleVerts, 3, triangleIndices, 3, glm::vec3());
	RegisterMesh("Triangle", triangleMesh);

	GLuint squareVBO;
	Vertex squareVerts[] =
	{
		Vertex(-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f),
		Vertex(-0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f),
		Vertex( 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f),
		Vertex( 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f)
	};

	int squareIndicies[] = { 0, 1, 2, 0, 2, 3 };

	Mesh* squareMesh = new Mesh(squareVerts, 4, squareIndicies, 6, glm::vec3());
	RegisterMesh("Square", squareMesh);

	Mesh* suzanne = new Mesh("suzanne.obj", glm::vec3());
	RegisterMesh("Suzanne", suzanne);

	Mesh* cube = new Mesh("cube.obj", glm::vec3(0.5f, 0.5f, 0.5f));
	RegisterMesh("Cube", cube);
}

void ResourceManager::GenerateMaterials(void)
{
	Material* standard = new Material(GetShader("StandardVS"), GetShader("StandardFS"));
	RegisterMaterial("Standard", standard);
}