#include "game.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "renderer.h"

unsigned int transform_location;
static std::vector<Chunk> chunks;

// Initialize the game
void game_setup() {
	transform_location = glGetUniformLocation(get_shader_program(), "transform");
	
	chunks.push_back(Chunk(-5, -20, 10));
}

// Game update
void game_update() {
	glm::mat4 trans = glm::mat4(1.0);

	glUseProgram(get_shader_program());
	glUniformMatrix4fv(transform_location, 1, GL_FALSE, glm::value_ptr(trans));
}

std::vector<Chunk> get_chunks() {
	return chunks;
}