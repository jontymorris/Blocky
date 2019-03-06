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
	while (!window.shouldWindowClose()) {
		window.pollEvents();
		
		renderer.clear();
		
		window.swapBuffers();
		renderer.checkError();
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
