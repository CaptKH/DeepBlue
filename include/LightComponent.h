#ifndef LIGHT_COMPONENT
#define LIGHT_COMPONENT

#include "Component.h"
#include "Light.h"

class LightComponent : public Component
{
private:
	Light* light;
	glm::vec3 initialPosition;

public:
	LightComponent(void);
	LightComponent(Light* l);
	~LightComponent(void);

	Light*	  GetLight(void)			{ return light;			  }
	glm::vec3 GetInitialPosition(void)	{ return initialPosition; }
};

#endif