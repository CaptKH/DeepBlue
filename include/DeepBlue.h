#ifndef DEEP_BLUE
#define DEEP_BLUE

#include "GLCore.h"
#include "Camera.h"

#include "InputManager.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "CameraManager.h"
#include "ResourceManager.h"

class DeepBlue
{
private:
	GLCore* core;

	InputManager*    iManager;
	EntityManager*   eManager;
	SystemManager*   sManager;
	CameraManager*   cManager;
	ResourceManager* rManager;

	Entity* test;

public:
	DeepBlue(void);
	~DeepBlue(void);

	void Initialize(void);
	void Run(void);
};

#endif