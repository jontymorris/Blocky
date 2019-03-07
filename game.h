#pragma once

#include "renderer.h"
#include "world.h"

class Game {
public:
	bool isRunning;
	
	Renderer renderer;
	World world;

	void init();
	void update();
	void render();
	void close();
};