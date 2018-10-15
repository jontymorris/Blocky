#pragma once

#include <glm/vec3.hpp>
#include "camera.h"

class Player {
public:
	Player();
	Player(int x, int y, int z);
	void update();
	glm::vec3 position;
	Camera camera;

	bool moving_foward;
	bool moving_back;
	bool moving_right;
	bool moving_left;
private:
	float move_speed;
};