#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "System.h"

class RenderSystem : public System
{
public:
	RenderSystem();
	~RenderSystem();

	virtual void Update(float dt, float tt) override;
};

#endif