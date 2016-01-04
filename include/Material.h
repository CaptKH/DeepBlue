#ifndef MATERIAL
#define MATERIAL

#include <Shader.h>

class Material
{
private:
	GLuint shaderProgram;
	GLuint transformUniform;
	GLuint viewUniform;

public:
	Material(Shader* vShader, Shader* fShader);

	GLuint GetProgram(void);
	GLuint GetViewUniform(void);
	GLuint GetTransformUniform(void);
};

#endif