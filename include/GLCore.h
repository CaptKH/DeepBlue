#ifndef GL_CORE
#define GL_CORE

#define GLEW_STATIC
#include "GLEW\glew.h"
#include "GLFW\glfw3.h"

#include "SystemManager.h"

class GLCore
{
private:
	GLFWwindow* window;

public:
	GLCore(void);
	~GLCore(void);

	bool Initialize(void);

	GLFWwindow* Window(void) { return window; }
};

#endif