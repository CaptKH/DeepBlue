#include <CameraComponent.h>

CameraComponent::CameraComponent(void)
{
	type = ComponentType::CAMERA;
	camera = new Camera();
}

CameraComponent::CameraComponent(Camera* c)
{
	type = ComponentType::CAMERA;
	memcpy(camera, c, sizeof(Camera));
	delete c;
}

CameraComponent::~CameraComponent(void)
{
	delete camera;
	camera = 0;
}

void CameraComponent::SetPosition(glm::vec3& p)
{
	camera->SetPosition(p);
}

Camera* CameraComponent::GetCamera(void)
{
	return camera;
}

