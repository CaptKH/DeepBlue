#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "Singleton.h"

#include "GLFW\glfw3.h"

class InputManager : public Singleton<InputManager>
{
private:
	bool keys[1024];
	float lastMouseX;
	float lastMouseY;

	bool firstMouse;

public:
	InputManager(void);
	~InputManager(void);

	void Initialize(GLFWwindow* window);
	void Update(float dt, float tt);

	void SetKey(int key, bool value);
	float LastMouseX(void);
	float LastMouseY(void);
	bool  FirstMouse(void);
	void  SetLastMouseX(float val);
	void  SetLastMouseY(float val);
	void  SetFirstMouse(bool val);
};

#endif