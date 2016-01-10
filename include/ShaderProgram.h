#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

#include <Shader.h>
#include <unordered_map>

#include <GLM\glm.hpp>

struct ShaderProgram
{
	GLuint program;
	Shader* vertexShader;
	Shader* fragmentShader;

	std::unordered_map<std::string, GLuint> uniforms;

	ShaderProgram(Shader* vShader, Shader* fShader);
	~ShaderProgram(void);

	GLuint GetUniform(std::string id);
	void   GenerateUniform(std::string uniform);
	void   SetFloat(std::string id, float data);
	void   SetVec2(std::string id, glm::vec2 data);
	void   SetVec3(std::string id, glm::vec3 data);
	void   SetMat4(std::string id, glm::mat4 data, bool inverse);
};

#endif