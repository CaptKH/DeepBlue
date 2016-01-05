#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "System.h"

#include <GLM\glm.hpp>

class RenderSystem : public System
{
private:
	glm::mat4 projectionMat;
	
public:
	RenderSystem();
	~RenderSystem();

	virtual void Update(float dt, float tt) override;
};

#endif