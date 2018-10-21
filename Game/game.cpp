#include "game.h"

#include <GLFW/glfw3.h>

Game::~Game() {
	chunks_thread.join();
}

void Game::setup() {
	running = true;
	renderer.setup();

	chunks_thread = std::thread(&Game::create_chunks, this);
}

void Game::create_chunks() {
	// Create some chunks
	for (int x = -5*CHUNK_SIZE; x < 10; x++) {
		for (int z = -5*CHUNK_SIZE; z < 10; z++) {
			Chunk new_chunk(x*CHUNK_SIZE, -CHUNK_SIZE-2, z*CHUNK_SIZE);
			
			chunks_mutex.lock();
			chunks.push_back(new_chunk);
			chunks_mutex.unlock();
		}
	}
}

// Game update
void Game::update() {
	player.update();
}

// Render the game
void Game::render() {
	renderer.render(this);
}

// Handle key input
void Game::key_callback(int key, int action) {
	// Foward
	if (key == GLFW_KEY_W) {
		if (action == GLFW_PRESS) {
			player.moving_foward = true;
			player.moving_back = false;
		} else if (action == GLFW_RELEASE) {
			player.moving_foward = false;
		}
	}

	// Back
	else if (key == GLFW_KEY_S) {
		if (action == GLFW_PRESS) {
			player.moving_back = true;
			player.moving_foward = false;
		}
		else if (action == GLFW_RELEASE) {
			player.moving_back = false;
		}
	}

	// Left
	else if (key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) {
			player.moving_left = true;
			player.moving_right = false;
		}
		else if (action == GLFW_RELEASE) {
			player.moving_left = false;
		}
	}

	// Right
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
	player.camera.mouse_move(x_pos, y_pos);
}