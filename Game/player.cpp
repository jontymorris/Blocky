#include "player.h"

Player::Player() : Player::Player(0, 0, 0) {};

Player::Player(int x, int y, int z) {
	position = glm::vec3(x, y, z);
	camera.position = position;
}

void Player::update() {
	camera.position = position;
}