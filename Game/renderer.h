#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "player.h"
#include "chunk.h"

class Renderer {
public:
	unsigned int shader_program, vao;
	unsigned int model_location, projection_location, view_location;
	unsigned int grass_texture;
	glm::mat4 projection, view, model;
	
	Renderer();
	void render(Player player, std::vector<Chunk> chunks);
};