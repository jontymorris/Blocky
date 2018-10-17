#include "game.h"

#include <GLFW/glfw3.h>
#include "player.h"

void Game::setup() {
	running = true;
	renderer.setup();

	// Create some chunks
	chunks.push_back(Chunk(12, -12, 0));
	chunks.push_back(Chunk(0, -12, 0));
}

// Game update
void Game::update() {
	player.update();
}

// Render the game
void Game::render() {
	renderer.render(player, chunks);
}

// Handle key input
void Game::key_callback(int key, int action) {
	if (key == GLFW_KEY_W) {
		if (action == GLFW_PRESS) {
			player.moving_foward = true;
			player.moving_back = false;
		} else if (action == GLFW_RELEASE) {
			player.moving_foward = false;
		}
	}

	else if (key == GLFW_KEY_S) {
		if (action == GLFW_PRESS) {
			player.moving_back = true;
			player.moving_foward = false;
		}
		else if (action == GLFW_RELEASE) {
			player.moving_back = false;
		}
	}

	else if (key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) {
			player.moving_left = true;
			player.moving_right = false;
		}
		else if (action == GLFW_RELEASE) {
			player.moving_left = false;
		}
	}

	else if (key == GLFW_KEY_D) {
		if (action == GLFW_PRESS) {
			player.moving_right = true;
			player.moving_left = false;
		}
		else if (action == GLFW_RELEASE) {
			player.moving_right = false;
		}
	}
}

// Handle mouse input
void Game::mouse_callback(double x_pos, double y_pos) {
	player.camera.mouse_update(x_pos, y_pos);
}