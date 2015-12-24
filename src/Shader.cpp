#include <Shader.h>
#include <FileIO.h>
#include <iostream>

Shader::Shader(std::string fileName, ShaderType t) 
{
	type = t;

	// Generate the shader
	const GLchar* shaderCode = ReadShaderFile("VertexShader.glsl").c_str();
	switch (t)
	{
		case(ShaderType::VERTEXSHADER) :
			shader = glCreateShader(GL_VERTEX_SHADER);
			break;
		case(ShaderType::FRAGMENTSHADER) :
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
		std::cout << "ERROR: Shader compilation failed.\n" << infoLog << std::endl;
	}
}