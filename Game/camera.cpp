#include "camera.h"

#include <glm/glm.hpp>
#include "constants.h"

Camera::Camera() {
	position = glm::vec3(0, 0, 0);
	up = glm::vec3(0, 1, 0);

	mouse_sensitivity = 0.05f;

	last_x = WINDOW_WIDTH / 2;
	last_y = WINDOW_HEIGHT / 2;

	update();
	first_move = true;
}

void Camera::mouse_move(float x_pos, float y_pos) {
	if (first_move)
	{
		last_x = x_pos;
		last_y = y_pos;
		first_move = false;
	}

	float x_offset = x_pos - last_x;
	float y_offset = y_pos - last_y;

	last_x = x_pos;
	last_y = y_pos;

	x_offset *= mouse_sensitivity;
	y_offset *= mouse_sensitivity;

	yaw += x_offset;
	pitch -= y_offset;

	update();
}

void Camera::update() {
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 new_front;
	new_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	new_front.y = sin(glm::radians(pitch));
	new_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(new_front);

	front_locked = front;
	front_locked.y = 0;
}