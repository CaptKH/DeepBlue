#ifndef DEEP_BLUE
#define DEEP_BLUE

#include "GLCore.h"

#include "EntityManager.h"
#include "SystemManager.h"
#include "ResourceManager.h"

class DeepBlue
{
private:
	GLCore* core;

	EntityManager*   eManager;
	SystemManager*   sManager;
	ResourceManager* rManager;

	Entity* test;

public:
	DeepBlue(void);
	~DeepBlue(void);

	void Initialize(void);
	void Run(void);
};

#endif