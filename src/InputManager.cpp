#include <InputManager.h>

#include <EntityManager.h>
#include <CameraComponent.h>
#include <Windows.h>

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

void InputManager::Update(float dt, float tt)
{
	EntityManager* eManager = EntityManager::Instance();
	Camera* c = eManager->GetComponent<CameraComponent>(eManager->Get("Camera"), ComponentType::CAMERA)->GetCamera();

	if (keys[GLFW_KEY_W]) {
		c->Move(CameraDirection::UP);
	}
	if (keys[GLFW_KEY_A]) {
		c->Move(CameraDirection::LEFT);
	}
	if (keys[GLFW_KEY_S]) {
		c->Move(CameraDirection::DOWN);
	}
	if (keys[GLFW_KEY_D]) {
		c->Move(CameraDirection::RIGHT);
	}
	if (keys[GLFW_KEY_Q]) {
		c->Move(CameraDirection::BACKWARD);
	}
	if (keys[GLFW_KEY_E]) {
		c->Move(CameraDirection::FORWARD);
	}
}

void InputManager::SetKey(int key, bool value)
{
	keys[key] = value;
}

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mode)
{
	InputManager* iManager = InputManager::Instance();

	if (action == GLFW_PRESS) {
		iManager->SetKey(key, true);
	}
	else  if (action == GLFW_RELEASE) {
		iManager->SetKey(key, false);
	}
}
