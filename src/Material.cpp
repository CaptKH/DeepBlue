#include <Material.h>
#include <iostream>

Material::Material(Shader& vShader, Shader& fShader)
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vShader.GetShader());
	glAttachShader(shaderProgram, fShader.GetShader());
	glLinkProgram(shaderProgram);

	// Check for errors in program compilation
	GLint  success;
	GLchar infoLog[512];
	glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR: Program compilation failed.\n" << infoLog << std::endl;
	}
}