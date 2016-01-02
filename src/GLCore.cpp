#include <GLCore.h>
#include <iostream>


// Input forward declarations
void key_callback(GLFWwindow* w, int key, int scancode, int action, int mode);

GLCore::GLCore(void)
{
}

GLCore::~GLCore(void)
{
}

bool GLCore::Initialize(void) 
{

	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL v 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Disallow legacy function calls
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create/verify window 
	window = glfwCreateWindow(1920, 1080, "Deep Blue Graphics Engine", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create window." << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << " Failed to initialize GLEW" << std::endl;
		return false;
	}

	// Initialize input
	glfwSetKeyCallback(window, key_callback);

	glViewport(0, 0, 1920, 1080);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	return true;
}

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mode)
{
	// Check if escape has been pressed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(w, GL_TRUE);
}

GLFWwindow* GLCore::Window(void)
{
	return window;
}