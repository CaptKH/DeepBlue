#include <CameraManager.h>

CameraManager::CameraManager(void)
{
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.5f));
	camera->UpdateViewMatrix();
}

CameraManager::~CameraManager(void)
{
	delete camera;
	camera = 0;
}

Camera* CameraManager::GetCamera(void)
{
	return camera;
}