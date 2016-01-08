#include <InputManager.h>

#include <EntityManager.h>
#include <CameraComponent.h>
#include <Windows.h>

// Input forward declarations
void key_callback(GLFWwindow* w, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* w, double mouseX, double mouseY);

InputManager::InputManager(void)
{
}

InputManager::~InputManager(void)
{
}

void InputManager::Initialize(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	firstMouse = true;
}

bool* InputManager::GetKeys(void)
{
	return keys;
}

void InputManager::SetKey(int key, bool value)
{
	keys[key] = value;
}

float InputManager::LastMouseX(void)
{
	return lastMouseX;
}

float InputManager::LastMouseY(void)
{
	return lastMouseY;
}

bool InputManager::FirstMouse(void)
{
	return firstMouse;
}

void InputManager::SetLastMouseX(float val)
{
	lastMouseX = val;
}

void InputManager::SetLastMouseY(float val)
{
	lastMouseY = val;
}

void InputManager::SetFirstMouse(bool val)
{
	firstMouse = val;
}

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mode)
{
	InputManager* iManager = InputManager::Instance();

	if (key == GLFW_KEY_ESCAPE) {
		glfwWindowShouldClose(w);
	}

	if (action == GLFW_PRESS) {
		iManager->SetKey(key, true);
	}
	else  if (action == GLFW_RELEASE) {
		iManager->SetKey(key, false);
	}
}

void mouse_callback(GLFWwindow* w, double mouseX, double mouseY)
{
	InputManager* iManager = InputManager::Instance();
	if (glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
		EntityManager* eManager = EntityManager::Instance();
		Camera* c = eManager->GetComponent<CameraComponent>(eManager->Get("Camera"), ComponentType::CAMERA)->GetCamera();

		float xOffset = mouseX - iManager->LastMouseX();
		float yOffset = iManager->LastMouseY() - mouseY;
		iManager->SetLastMouseX(mouseX);
		iManager->SetLastMouseY(mouseY);

		float sensitivity = 0.1f;
		xOffset *= sensitivity;
		yOffset *= sensitivity;

		c->Rotate(xOffset, yOffset);
	}
	else {
		iManager->SetLastMouseX(mouseX);
		iManager->SetLastMouseY(mouseY);
	}
}
