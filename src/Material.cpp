#include <Material.h>
#include <iostream>

Material::Material(Shader* vShader, Shader* fShader)
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vShader->GetShader());
	glAttachShader(shaderProgram, fShader->GetShader());
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// Check for errors in program compilation
	GLint  success;
	GLchar infoLog[512];
	glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR: Program compilation failed.\n" << infoLog << std::endl;
	}

	transformUniform = glGetUniformLocation(shaderProgram, "transform");
	viewUniform = glGetUniformLocation(shaderProgram, "view");
	projectionUniform = glGetUniformLocation(shaderProgram, "projection");
	originUniform = glGetUniformLocation(shaderProgram, "origin");
}

GLuint Material::GetProgram(void)
{
	return shaderProgram;
}

GLuint Material::GetViewUniform(void)
{
	return viewUniform;
}

GLuint Material::GetTransformUniform(void)
{
	return transformUniform;
}

GLuint Material::GetProjectionUniform(void)
{
	return projectionUniform;
}

GLuint Material::GetOriginUniform(void)
{
	return originUniform;
}