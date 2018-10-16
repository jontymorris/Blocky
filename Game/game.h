#pragma once

#include <glm/glm.hpp>

#include "renderer.h"
#include "player.h"
#include "chunk.h"

class Game {
public:
	bool running;
	
	Player player;
	std::vector<Chunk> chunks;

	void setup();
	void update();
	void render();
	
	void key_callback(int key, int action);
	void mouse_callback(double x_pos, double y_pos);
private:
	Renderer renderer;
};