#ifndef MATERIAL
#define MATERIAL

#include <Shader.h>
#include <Texture.h>
#include <unordered_map>

class Material
{
private:
	GLuint shaderProgram;
	std::unordered_map<std::string, GLuint> uniforms;
	std::unordered_map<std::string, Texture*> textures;

public:
	Material(Shader* vShader, Shader* fShader);

	GLuint   GetProgram(void);
	GLuint   GetUniform(std::string id);
	bool     GenerateUniform(std::string id);
	Texture* GetTexture(std::string id);
	bool     AddTexture(std::string id, Texture* t);
};

#endif