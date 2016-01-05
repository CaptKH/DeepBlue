#ifndef MATERIAL
#define MATERIAL

#include <Shader.h>

class Material
{
private:
	GLuint shaderProgram;
	GLuint transformUniform;
	GLuint viewUniform;
	GLuint projectionUniform;
	GLuint originUniform;

public:
	Material(Shader* vShader, Shader* fShader);

	GLuint GetProgram(void);
	GLuint GetViewUniform(void);
	GLuint GetTransformUniform(void);
	GLuint GetProjectionUniform(void);
	GLuint GetOriginUniform(void);
};

#endif