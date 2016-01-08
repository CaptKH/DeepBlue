#ifndef INPUT_SYSTEM
#define INPUT_SYSTEM

#include "System.h"
#include "InputManager.h"

class InputSystem : public System
{
	InputManager* iManager;

public:
	InputSystem(void);
	~InputSystem(void);

	virtual void Update(float dt, float tt) override;
};

#endif