#ifndef MATERIAL
#define MATERIAL

#include <Shader.h>

class Material
{
private:
	GLuint shaderProgram;

public:
	Material(Shader* vShader, Shader* fShader);

	GLuint GetProgram(void);
};

#endif