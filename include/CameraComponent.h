#ifndef CAMERA_COMPONENT
#define CAMERA_COMPONENT

#include "Component.h"
#include "Camera.h"

class CameraComponent : public Component
{
private:
	Camera* camera;

public:
	CameraComponent(void);
	CameraComponent(Camera* c);
	virtual ~CameraComponent(void);

	Camera* GetCamera(void);
	void SetPosition(glm::vec3& p);
};

#endif