#include "camera.h"

Camera::Camera() {
	position = glm::vec3(0, 0, 3);
	front = glm::vec3(0, 0, -1);
	up = glm::vec3(0, 1, 0);
}