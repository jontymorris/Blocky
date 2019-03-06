#include "game.h"
#include "window.h"
#include <iostream>

Game game;
Window window;

// Setup the game
void init() {
	window.init();
	game.init();
}

// Game loop
void loop() {
	const double updateLimit = 1.0 / 60.0;
	double last = window.getTime();
	double now = 0;
	double timer = 0;
	double delta = 0;
	int frames = 0;
	int updates = 0;
	
	while (game.isRunning) {
		// should the game close?
		if (window.shouldWindowClose()) {
			game.isRunning = false;
		}
		
		// refresh timers
		now = window.getTime();
		delta += (now - last) / updateLimit;
		last = now;
		
		window.pollEvents();
		
		// update
		while (delta >= 1.0) {
			updates++;
			game.update();
			delta--;
		}
		
		// render
		frames++;
		game.render();
		window.swapBuffers();
		
		// one second interval
		if (window.getTime() - timer > 1.0) {
			timer++;
			std::cout << "FPS: " << frames << ", Updates: " << updates << std::endl;
			frames = 0;
			updates = 0;
		}
	}
}

// Close the game
void close() {
	game.close();
	window.close();
}

int main() {
	std::cout << "Game running..." << std::endl;
	
	init();
	loop();
	close();
	
	return 0;
}
