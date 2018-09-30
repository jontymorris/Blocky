#include "main.h"

#include <stdio.h>
#include "renderer.h"
#include "game.h"

int main() {
	// Init GLFW
	if (!glfwInit()) {
		printf("Failed to init GLFW\n");
		return -1;
	}

	// Add window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	// Create the window
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game", NULL, NULL);
	if (!window) {
		printf("Failed to create the window\n");
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// Load OpenGL
	if (!gladLoadGL()) {
		printf("Glad failed to load OpenGL\n");
		return -1;
	}

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(0.3f, 0.4f, 0.5f, 1.0f);

	// Setup the game
	render_setup();
	game_setup();
	
	// Game loop
	double fps_limit = 1.0 / 60.0;
	double last_time = glfwGetTime();
	double timer = last_time;
	double delta_time = 0, now = 0;
	int frames = 0, updates = 0;

	while (!glfwWindowShouldClose(window)) {
		now = glfwGetTime();
		delta_time += (now - last_time) / fps_limit;
		last_time = now;

		while (delta_time >= 1.0) {
			game_update();
			updates += 1;
			delta_time -= 1;
		}
		
		render_game();
		frames += 1;

		if (glfwGetTime() - timer >= 1.0) {
			timer += 1;
			//printf("FPS: %i\nUpdates: %i\n\n", frames, updates);
			updates = 0;
			frames = 0;
		}

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}