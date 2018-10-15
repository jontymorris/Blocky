#pragma once

#include <glm/vec3.hpp>

class Camera {
public:
	Camera();
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
};