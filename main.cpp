#include "renderer.h"
#include "window.h"
#include <iostream>

Window window;
Renderer renderer;

// Setup the game
void init() {
	window.init();
	renderer.init();
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
	
	while (!window.shouldWindowClose()) {
		// refresh timers
		now = window.getTime();
		delta += (now - last) / updateLimit;
		last = now;
		
		window.pollEvents();
		
		// update
		while (delta >= 1.0) {
			updates++;
			delta--;
		}
		
		// render
		frames++;
		renderer.clear();
		renderer.checkError();
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
	window.close();
}

int main() {
	std::cout << "Game running..." << std::endl;
	
	init();
	loop();
	close();
	
	std::cout << "Game closed" << std::endl;
	return 0;
}
