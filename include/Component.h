#ifndef COMPONENT
#define COMPONENT

enum ComponentType { BASE = 0, RENDER = 1 };

class Component
{
protected:
	ComponentType type;
	const unsigned entityID;

public:
	Component(void);
	Component(const unsigned eID, ComponentType t);
	~Component(void);

	const unsigned GetEntityID(void);
};

#endif