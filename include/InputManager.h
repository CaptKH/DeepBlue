#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "Singleton.h"

#include "GLFW\glfw3.h"

class InputManager : public Singleton<InputManager>
{
public:
	InputManager(void);
	~InputManager(void);

	void Initialize(GLFWwindow* window);
};

#endif