#pragma once

#include <glm/vec3.hpp>

class Camera {
public:
	Camera();
	
	glm::vec3 position;
	glm::vec3 front, front_locked;
	glm::vec3 up;

	void mouse_move(float x_pos, float y_pos);
private:
	float yaw, pitch;
	float mouse_sensitivity;
	float last_x, last_y;
	bool first_move;

	void update();
};