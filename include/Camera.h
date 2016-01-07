#ifndef __CAMERA
#define __CAMERA

#include <GLM/glm.hpp>

enum CameraDirection { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, FORWARD = 4, BACKWARD = 5};

class Camera
{
private:
	glm::mat4 view;
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;

	float yaw;
	float pitch;
	float speed;

public:
	Camera(void);
	Camera(glm::vec3 p);
	~Camera(void);

	glm::vec3 Position(void);
	void	  SetPosition(glm::vec3& p);
	void      Rotate(float y, float p);
	glm::mat4 ViewMatrix(void);

	void UpdateViewMatrix(void);
	void Move(CameraDirection direction);
};

#endif