#include <Camera.h>

#include <EntityManager.h>
#include <PhysicsComponent.h>

#include <GLM/gtc/matrix_transform.hpp>

Camera::Camera(void)
	: position(glm::vec3()), up(glm::vec3(0.0f, 1.0f, 0.0f)), right(glm::vec3(1.0f, 0.0f, 0.0f)), yaw(270.0f), pitch(0.0f), speed(5.0f)
{
	
	Rotate(0.0f, 0.0f);
	UpdateViewMatrix();
}

Camera::Camera(glm::vec3 p)
	: position(p), up(glm::vec3(0.0f, 1.0f, 0.0f)), right(glm::vec3(1.0f, 0.0f, 0.0f)), yaw(270.0f), pitch(0.0f), speed(5.0f)
{
	Rotate(0, 0);
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

void Camera::Rotate(float y, float p)
{
	yaw += y;
	pitch += p;

	if (pitch > 89.9f)
		pitch = 89.9f;
	if (pitch < -89.9f)
		pitch = -89.9f;

	float yawRad = glm::radians(yaw);

	glm::vec3 camFront = glm::vec3();
	camFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	camFront.y = sin(glm::radians(pitch));
	camFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(camFront);
	right = glm::cross(front, up);
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