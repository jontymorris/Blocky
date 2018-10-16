#pragma once

#include <glm/vec3.hpp>
#include "camera.h"

class Player {
public:
	glm::vec3 position;
	Camera camera;

	bool moving_foward;
	bool moving_back;
	bool moving_right;
	bool moving_left;

	Player();
	Player(int x, int y, int z);

	void update();
private:
	float move_speed;
};