#include <ResourceManager.h>

ResourceManager::ResourceManager(void)
{
	meshes = std::unordered_map<std::string, Mesh*>();
	materials = std::unordered_map<std::string, Material*>();
	shaders = std::unordered_map<std::string, Shader*>();

	GenerateShaders();
	GenerateShaderPrograms();
	GenerateTextures();
	GenerateMaterials();
	GenerateMeshes();
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

Texture* ResourceManager::GetTexture(std::string id)
{
	if (textures.find(id) == textures.end())
		return nullptr;
	else
		return textures.find(id)->second;
}

bool ResourceManager::RegisterTexture(std::string id, Texture* texture)
{
	if (textures.find(id) != textures.end())
		return false;
	else
		textures.emplace(id, texture);
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

ShaderProgram* ResourceManager::GetShaderProgram(std::string id)
{
	if (shaderPrograms.find(id) == shaderPrograms.end())
		return nullptr;
	return shaderPrograms.find(id)->second;
}

bool ResourceManager::RegisterShaderProgram(std::string id, ShaderProgram* shaderProgram)
{
	if (shaderPrograms.find(id) != shaderPrograms.end()) {
		return false;
	}
	shaderPrograms.emplace(id, shaderProgram);
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

	Shader* textureFS = new Shader("TextureFS.glsl", ShaderType::FRAGMENTSHADER);
	RegisterShader("TextureFS", textureFS);
}

void ResourceManager::GenerateShaderPrograms(void) {
	ShaderProgram* standard = new ShaderProgram(GetShader("StandardVS"), GetShader("StandardFS"));
	standard->GenerateUniform("origin");
	standard->GenerateUniform("transform");
	standard->GenerateUniform("view");
	standard->GenerateUniform("projection");
	standard->GenerateUniform("normalMatrix");
	standard->GenerateUniform("objTexture");;
	standard->GenerateUniform("light.position");
	standard->GenerateUniform("light.color");
	standard->GenerateUniform("light.strength");
	standard->GenerateUniform("cameraPos");
	RegisterShaderProgram("Standard", standard);

	ShaderProgram* texture = new ShaderProgram(GetShader("StandardVS"), GetShader("TextureFS"));
	texture->GenerateUniform("origin");
	texture->GenerateUniform("transform");
	texture->GenerateUniform("view");
	texture->GenerateUniform("projection");
	texture->GenerateUniform("normalMatrix");
	texture->GenerateUniform("objTexture");;
	texture->GenerateUniform("light.position");
	texture->GenerateUniform("light.color");
	texture->GenerateUniform("light.strength");
	texture->GenerateUniform("cameraPos");
	RegisterShaderProgram("Texture", texture);
}

void ResourceManager::GenerateMeshes(void)
{
	GLuint triangleVBO;
	Vertex triangleVerts[] =
	{
		Vertex(-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f),
		Vertex( 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f),
		Vertex( 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 1.0f)
	};

	int triangleIndices[] = { 0, 1, 2 };

	Mesh* triangleMesh = new Mesh(triangleVerts, 3, triangleIndices, 3, glm::vec3());
	RegisterMesh("Triangle", triangleMesh);

	GLuint squareVBO;
	Vertex squareVerts[] =
	{
		Vertex( 0.5f,   0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
		Vertex( 0.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f),
		Vertex(-0.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f),
		Vertex(-0.5f,   0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f)
	};

	int squareIndicies[] = { 2, 1, 0, 2, 0, 3 };

	Mesh* squareMesh = new Mesh(squareVerts, 4, squareIndicies, 6, glm::vec3());
	RegisterMesh("Square", squareMesh);


	// .objs
	Mesh* sphere = new Mesh("sphere.obj");
	RegisterMesh("Sphere", sphere);

	//Mesh* deathStar = new Mesh("death_star.obj");
	//RegisterMesh("DeathStar", deathStar);

	//Mesh* milleniumFalcon = new Mesh("millenium_falcon.obj");
	//RegisterMesh("MilleniumFalcon", milleniumFalcon);

	Mesh* gollum = new Mesh("gollum.obj", glm::vec3(1.5f, 1.0f, -11.0f));
	RegisterMesh("Gollum", gollum);

	Mesh* starDestroyer = new Mesh("star_destroyer.obj");
	RegisterMesh("StarDestroyer", starDestroyer);

	Mesh* suzanne = new Mesh("suzanne.obj", glm::vec3());
	RegisterMesh("Suzanne", suzanne);

	Mesh* cube = new Mesh("cube.obj", glm::vec3(0.5f, 0.5f, 0.5f));
	RegisterMesh("Cube", cube);

	//Mesh* stormTrooper = new Mesh("stormtrooper.obj", glm::vec3(), GetTexture("StormtrooperTexture"));
	//RegisterMesh("StormTrooper", stormTrooper);
}

void ResourceManager::GenerateMaterials(void)
{
	Material* standard = new Material(GetShaderProgram("Standard"));
	RegisterMaterial("Standard", standard);

	Material* texture = new Material(GetShaderProgram("Texture"));
	texture->AddTexture("Container2", GetTexture("Container2"));
	RegisterMaterial("Texture", texture);
}

void ResourceManager::GenerateTextures(void)
{
	Texture* container = new Texture("container.jpg", ImageFileType::JPG);
	RegisterTexture("Container", container);

	Texture* container2 = new Texture("container2.png", ImageFileType::PNG);
	RegisterTexture("Container2", container2);

	Texture* gun = new Texture("M1911.jpg", ImageFileType::JPG);
	RegisterTexture("M1911", gun);
}