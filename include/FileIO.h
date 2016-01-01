#ifndef FILE_IO
#define FILE_IO

#include <string>
#include <fstream>

std::string ReadShaderFile(std::string fileName)
{
	// String to store shader code
	std::string shaderCode;
	// Create stream to file
	std::ifstream shaderStream("shaders/" + fileName, std::ios::in);

	// Open stream
	if (shaderStream.is_open()) {
		// To store shader file lines
		std::string line;

		// Fill shaderCode with shader data
		while (getline(shaderStream, line)) {
			shaderCode += "\n" + line;
		}

		// Close the stream
		shaderStream.close();
	}

	return shaderCode;
}

#endif