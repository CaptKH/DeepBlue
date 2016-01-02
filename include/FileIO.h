#ifndef FILE_IO
#define FILE_IO

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


#include <GLEW\glew.h>

std::string ReadShaderFile(std::string fileName)
{
	std::string filePath = "shaders/" + fileName;
	// String to store shader code
	std::string shaderCode;
	// Create stream to file
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::badbit);

	try {
		shaderFile.open(filePath);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();

		shaderCode = shaderStream.str();
	}
	catch (std::ifstream::failure e) {

	}

	return shaderCode;
}

#endif