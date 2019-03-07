#include "game.h"

// Setup the game
void Game::init() {
	isRunning = true;
	
	renderer.init();
	world.init();
}

// Perform a game update
void Game::update() {
	
}

// Render the game
void Game::render() {
	renderer.clear();
	renderer.renderWorld(world);
}

// Close the game
void Game::close() {
	
}