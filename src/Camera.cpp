#include <Camera.h>

#include <EntityManager.h>
#include <PhysicsComponent.h>

#include <GLM/gtc/matrix_transform.hpp>

Camera::Camera(void)
{
	position = glm::vec3();
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	right = glm::vec3(1.0f, 0.0f, 0.0f);
	speed = 1.0f;

	UpdateViewMatrix();
}

Camera::Camera(glm::vec3 p)
	: position(p)
{
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	right = glm::vec3(1.0f, 0.0f, 0.0f);
	speed = 1.0f;

	UpdateViewMatrix();
}

Camera::~Camera(void)
{
}

glm::vec3 Camera::Position(void)
{
	return position;
}

void Camera::SetPosition(glm::vec3& p)
{
	position = p;
}

glm::mat4 Camera::ViewMatrix(void)
{
	UpdateViewMatrix();
	return view;
}

void Camera::UpdateViewMatrix(void)
{
	view = glm::lookAt(position, position + front, up);
}

void Camera::Move(CameraDirection direction)
{
	EntityManager* eManager = EntityManager::Instance();
	PhysicsComponent* pComponent = eManager->GetComponent<PhysicsComponent>(eManager->Get("Camera"), ComponentType::PHYSICS);

	switch (direction) {
		case CameraDirection::UP:
			pComponent->Accelerate(up * speed);
			break;
		case CameraDirection::LEFT:
			pComponent->Accelerate(-right * speed);
			break;
		case CameraDirection::DOWN:
			pComponent->Accelerate(-up * speed);
			break;
		case CameraDirection::RIGHT:
			pComponent->Accelerate(right * speed);
			break;
		case CameraDirection::FORWARD:
			pComponent->Accelerate(front * speed);
			break;
		case CameraDirection::BACKWARD:
			pComponent->Accelerate(-front * speed);
			break;
	}
}