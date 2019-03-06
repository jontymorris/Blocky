#include "window.h"
#include <iostream>

// Sets up GLFW and the window
void Window::init() {
	windowWidth = 1280;
	windowHeight = 720;
	
	// init GLFW
	if (!glfwInit()) {
		std::cout << "Failed to init GLFW" << std::endl;
	}
	
	// create the window
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	
	window = glfwCreateWindow(windowWidth, windowHeight, "Blocky", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create window" << std::endl;
	}
	
	glfwSwapInterval(1);
	glfwMakeContextCurrent(window);
}

// Close the window and finish with GLFW
void Window::close() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

// Poll the GLFW events
void Window::pollEvents() {
	glfwPollEvents();
}

// Swap the window buffers
void Window::swapBuffers() {
	glfwSwapBuffers(window);
}

// Checks if the window should close
bool Window::shouldWindowClose() {
	return glfwWindowShouldClose(window);
}

// Returns the time in mills
double Window::getTime() {
	return glfwGetTime();
}