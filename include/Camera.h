#ifndef CAMERA
#define CAMERA

#include <GLM/glm.hpp>

class Camera
{
private:
	glm::vec3 position;
	glm::vec3 up;

	glm::mat4 view;

public:
	Camera(void);
	Camera(glm::vec3 p);
	~Camera(void);

	glm::vec3 Position(void);
	glm::mat4 ViewMatrix(void);

	void UpdateViewMatrix(void);
	void Move(glm::vec3 trans);
};

#endif