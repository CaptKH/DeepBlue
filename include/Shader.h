#ifndef SHADER
#define SHADER

#include "GLEW\glew.h"
#include "GLFW\glfw3.h"

#include <string>

enum ShaderType{ VERTEXSHADER = 0, FRAGMENTSHADER = 1, GEOMETRYSHADER = 2};

class Shader
{
private:
	GLuint     shader;
	ShaderType type;

public:
	Shader(std::string fileName, ShaderType t);
	
	GLuint     GetShader(void) { return shader; }
	ShaderType GetType(void)   { return type; }
};

#endif