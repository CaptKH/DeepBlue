#ifndef CAMERA_MANAGER
#define CAMERA_MANAGER

#include "Singleton.h"
#include "Camera.h"

class CameraManager : public Singleton<CameraManager>
{
private:
	Camera* camera;

public:
	CameraManager(void);
	~CameraManager(void);

	Camera* GetCamera(void);
};

#endif