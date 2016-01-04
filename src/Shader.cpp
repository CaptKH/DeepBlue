#include <Shader.h>
#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(std::string fileName, ShaderType t) 
{
	type = t;

	std::string filePath = "shaders/" + fileName;
	std::string shaderString;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::badbit);

	try {
		shaderFile.open(filePath);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();

		shaderString = shaderStream.str();
	}
	catch (std::ifstream::failure e) {

	}
	const GLchar* shaderCode = shaderString.c_str();
	switch (t)
	{
		case ShaderType::VERTEXSHADER:
			shader = glCreateShader(GL_VERTEX_SHADER);
			break;
		case ShaderType::FRAGMENTSHADER:
			shader = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		default:
			shader = glCreateShader(GL_GEOMETRY_SHADER);
	}
	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);

	// Check for errors in shader compilation
	GLint  success;
	GLchar infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR: Shader compilation failed. " << t << "\n" << infoLog << std::endl;
	}
}

Shader::~Shader(void)
{
	glDeleteShader(shader);
}