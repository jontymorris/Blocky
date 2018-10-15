#include "player.h"

#include <glm/glm.hpp>

// DEBUG
#include <stdio.h>

Player::Player() : Player::Player(0, 0, 0) {};

Player::Player(int x, int y, int z) {
	position = glm::vec3(x, y, z);
	camera.position = position;
	move_speed = 0.05f;
}

void Player::update() {
	// Move the player
	if (moving_foward) {
		position += camera.front * move_speed;
	}
	else if (moving_back) {
		position -= camera.front * move_speed;
	}

	if (moving_right) {
		position += glm::normalize(glm::cross(camera.front, camera.up)) * move_speed;
	}
	else if (moving_left) {
		position -= glm::normalize(glm::cross(camera.front, camera.up)) * move_speed;
	}

	// Update the camera position
	camera.position = position;
}