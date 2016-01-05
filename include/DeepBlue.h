#ifndef DEEP_BLUE
#define DEEP_BLUE

#include "GLCore.h"
#include "Camera.h"

#include "InputManager.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "ResourceManager.h"

class DeepBlue
{
private:
	GLCore* core;

	InputManager*    iManager;
	EntityManager*   eManager;
	SystemManager*   sManager;
	ResourceManager* rManager;

	float totalTime;
	float deltaTime;

public:
	DeepBlue(void);
	~DeepBlue(void);

	void Initialize(void);
	void Run(void);
};

#endif