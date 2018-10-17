#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "player.h"
#include "chunk.h"

class Renderer {
public:
	unsigned int shader_program;
	unsigned int grass_texture;

	unsigned int model_location, projection_location, view_location;
	glm::mat4 projection, view, model;
	
	void setup();
	void render(Player player, std::vector<Chunk> chunks);
};