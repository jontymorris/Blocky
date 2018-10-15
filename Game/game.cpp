#include "game.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "player.h"

// Initialize the game
Game::Game() {
	// Create some chunks
	chunks.push_back(Chunk(0, -10, -50));
}

// Game update
void Game::update() {
	player.update();
}