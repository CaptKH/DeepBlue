#include <InputManager.h>
#include <CameraManager.h>

// Input forward declarations
void key_callback(GLFWwindow* w, int key, int scancode, int action, int mode);

InputManager::InputManager(void)
{
}

InputManager::~InputManager(void)
{
}

void InputManager::Initialize(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
}

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mode)
{
	Camera* cam = CameraManager::Instance()->GetCamera();

	// Check if escape has been pressed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(w, GL_TRUE);
	if (key == GLFW_KEY_W && action == GLFW_REPEAT)
		cam->Move(glm::vec3( 0.0f, 0.01f, 0));
	if (key == GLFW_KEY_A && action == GLFW_REPEAT)
		cam->Move(glm::vec3(-0.01f,  0, 0));
	if (key == GLFW_KEY_S && action == GLFW_REPEAT)
		cam->Move(glm::vec3(0, -0.01f, 0));
	if (key == GLFW_KEY_D && action == GLFW_REPEAT)
		cam->Move(glm::vec3( 0.01f,  0, 0));
}

