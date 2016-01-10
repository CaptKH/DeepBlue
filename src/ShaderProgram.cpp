#include <ShaderProgram.h>
#include <iostream>
#include <GLM\gtc\type_ptr.hpp>

ShaderProgram::ShaderProgram(Shader* vShader, Shader* fShader)
{
	vertexShader = vShader;
	fragmentShader = fShader;

	program = glCreateProgram();
	glAttachShader(program, vShader->GetShader());
	glAttachShader(program, fShader->GetShader());
	glLinkProgram(program);
	glUseProgram(program);

	// Check for errors in program compilation
	GLint  success;
	GLchar infoLog[512];
	glGetShaderiv(program, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR: Program compilation failed.\n" << infoLog << std::endl;
	}
}

ShaderProgram::~ShaderProgram(void)
{
}

GLuint ShaderProgram::GetUniform(std::string id)
{
	if (uniforms.find(id) == uniforms.end()) {
		return 0;
	}
	return uniforms.find(id)->second;
}

void ShaderProgram::GenerateUniform(std::string uniform)
{
	if (uniforms.find(uniform) != uniforms.end()) {
		return;
	}
	GLuint toAdd = glGetUniformLocation(program, uniform.c_str());
	uniforms.emplace(uniform, toAdd);
}

void ShaderProgram::SetFloat(std::string id, float data)
{
	glUniform1fv(GetUniform(id), 1, new float(data));
}

void ShaderProgram::SetVec2(std::string id, glm::vec2 data)
{
	glUniform2fv(GetUniform(id), 1, glm::value_ptr(data));
}

void ShaderProgram::SetVec3(std::string id, glm::vec3 data) 
{
	glUniform3fv(GetUniform(id), 1, glm::value_ptr(data));
}

void ShaderProgram::SetMat4(std::string id, glm::mat4 data, bool inverse)
{
	if (inverse) {
		glUniformMatrix4fv(GetUniform(id), 1, GL_TRUE, glm::value_ptr(data));
	}
	else {
		glUniformMatrix4fv(GetUniform(id), 1, GL_FALSE, glm::value_ptr(data));
	}
}