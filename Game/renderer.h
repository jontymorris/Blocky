#pragma once

#include <glm/glm.hpp>
#include "game.h"

class Renderer {
public:
	unsigned int shader_program, vao;
	unsigned int model_location, projection_location, view_location;
	unsigned int grass_texture;
	glm::mat4 projection, view, model;
	
	Renderer();
	void render(Game game);
};
