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
}

GLuint Material::GetProgram(void)
{
	return shaderProgram;
}

GLuint Material::GetUniform(std::string id)
{
	if (uniforms.find(id) == uniforms.end())
		return 0;

	return uniforms.find(id)->second;
}

bool Material::GenerateUniform(std::string id) {
	if (uniforms.find(id) != uniforms.end())
		return false;
	GLuint newUniform = glGetUniformLocation(shaderProgram, id.c_str());
	uniforms.emplace(id, newUniform);
	return true;
}

Texture* Material::GetTexture(std::string id)
{
	if (textures.find(id) == textures.end())
		return 0;
	return textures.find(id)->second;
}

bool Material::AddTexture(std::string id, Texture* t)
{
	if (textures.find(id) != textures.end())
		return false;
	textures.emplace(id, t);
	return true;
}