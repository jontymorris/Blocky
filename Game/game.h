#pragma once

#include <glm/glm.hpp>

#include "renderer.h"
#include "player.h"
#include "chunk.h"

class Game {
public:
	Player player;
	std::vector<Chunk> chunks;

	void setup();
	void update();
	void render();
	void key_callback(int key, int action);
private:
	Renderer renderer;
};