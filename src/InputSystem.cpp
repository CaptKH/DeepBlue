#include <InputSystem.h>
#include <CameraComponent.h>

InputSystem::InputSystem(void)
{
	iManager = InputManager::Instance();
}

InputSystem::~InputSystem(void)
{
}

void InputSystem::Update(float dt, float tt)
{
	bool* keys = iManager->GetKeys();
	Camera* c = eManager->GetComponent<CameraComponent>(eManager->Get("Camera"), ComponentType::CAMERA)->GetCamera();

	if (keys[GLFW_KEY_W]) {
		c->Move(CameraDirection::FORWARD);
	}
	if (keys[GLFW_KEY_A]) {
		c->Move(CameraDirection::LEFT);
	}
	if (keys[GLFW_KEY_S]) {
		c->Move(CameraDirection::BACKWARD);
	}
	if (keys[GLFW_KEY_D]) {
		c->Move(CameraDirection::RIGHT);
	}
	if (keys[GLFW_KEY_Q]) {
		c->Move(CameraDirection::DOWN);
	}
	if (keys[GLFW_KEY_E]) {
		c->Move(CameraDirection::UP);
	}
}