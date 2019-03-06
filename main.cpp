#include "renderer.h"
#include "window.h"
#include <iostream>

Window window;
Renderer renderer;

int main() {
	std::cout << "Game running..." << std::endl;
	
	window.init();
	renderer.init();
	
	while (!window.shouldWindowClose()) {
		window.pollEvents();
		
		renderer.clear();
		
		window.swapBuffers();
		renderer.checkError();
	}
	
	std::cout << "Game closed" << std::endl;
	return 0;
}