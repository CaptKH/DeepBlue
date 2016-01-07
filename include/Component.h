#ifndef COMPONENT
#define COMPONENT

enum ComponentType { BASE = 0, RENDER = 1, TRANSFORM = 2, CAMERA = 3, PHYSICS = 4, LIGHT = 5};

class Component
{
protected:
	ComponentType type;

public:
	Component(void);
	virtual ~Component(void);

	ComponentType GetType(void);

	bool operator == (Component* other);
};

#endif