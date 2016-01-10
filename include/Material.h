#ifndef MATERIAL
#define MATERIAL

#include <Texture.h>
#include <ShaderProgram.h>
#include <unordered_map>

class Material
{
private:
	ShaderProgram* shaderProgram;
	std::unordered_map<std::string, Texture*> textures;

public:
	Material(ShaderProgram* sProgram);

	ShaderProgram*   GetProgram(void);
	GLuint			 GetTexture(std::string id);
	bool			 AddTexture(std::string id, Texture* t);
};

#endif