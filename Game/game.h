#pragma once

#include <glm/glm.hpp>

#include "player.h"
#include "chunk.h"

class Game {
public:
	Player player;
	std::vector<Chunk> chunks;

	Game();
	void update();
};