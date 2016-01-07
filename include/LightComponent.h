#ifndef LIGHT_COMPONENT
#define LIGHT_COMPONENT

#include "Component.h"
#include "Light.h"

class LightComponent : public Component
{
private:
	Light* light;

public:
	LightComponent(void);
	LightComponent(Light* l);
	~LightComponent(void);

	Light* GetLight(void);
};

#endif