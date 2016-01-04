#include <Camera.h>
#include <GLM/gtc/matrix_transform.hpp>

Camera::Camera(void)
{
	position = glm::vec3();
	up = glm::vec3(0.0f, 1.0f, 0.0f);
}

Camera::Camera(glm::vec3 p)
	: position(p)
{
	up = glm::vec3(0.0f, 1.0f, 0.0f);
}

Camera::~Camera(void)
{
}

glm::vec3 Camera::Position(void)
{
	return position;
}

glm::mat4 Camera::ViewMatrix(void)
{
	return view;
}

void Camera::UpdateViewMatrix(void)
{
	glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);

	view = glm::lookAt(position, target, up);
}

void Camera::Move(glm::vec3 trans)
{
	position += trans;
	UpdateViewMatrix();
}