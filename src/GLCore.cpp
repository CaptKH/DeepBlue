#include <GLCore.h>
#include <iostream>

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

	glViewport(0, 0, 1920, 1080);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	return true;
}

GLFWwindow* GLCore::Window(void)
{
	return window;
}