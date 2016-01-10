#include <Material.h>
#include <iostream>

Material::Material(ShaderProgram* sProgram)
{
	shaderProgram = (ShaderProgram*)malloc(sizeof(ShaderProgram));
	memcpy(shaderProgram, sProgram, sizeof(ShaderProgram));
}

ShaderProgram* Material::GetProgram(void)
{
	return shaderProgram;
}

GLuint Material::GetTexture(std::string id)
{
	if (textures.find(id) == textures.end())
		return 0;
	return textures.find(id)->second->GetTexture();
}

bool Material::AddTexture(std::string id, Texture* t)
{
	if (textures.find(id) != textures.end())
		return false;
	textures.emplace(id, t);
	return true;
}