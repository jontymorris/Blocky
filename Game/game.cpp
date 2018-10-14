#include "game.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "renderer.h"

unsigned int model_location, projection_location, view_location;
glm::mat4 projection, view, model;

static std::vector<Chunk> chunks;

float rotation;

// Initialize the game
void game_setup() {
	projection_location = glGetUniformLocation(get_shader_program(), "projection");
	view_location = glGetUniformLocation(get_shader_program(), "view");
	model_location = glGetUniformLocation(get_shader_program(), "model");
	glUseProgram(get_shader_program());

	// Projection matrix
	projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
	glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));
	
	// View matrix
	view = glm::mat4(1);
	glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));

	// Model matrix
	glm::mat4(1.0);
	glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));

	// Create some chunks
	chunks.push_back(Chunk(0, -10, -50));

	rotation = 0;
}

// Game update
void game_update() {
	rotation += 0.001f;

	model = glm::mat4(1);
	model = glm::rotate(model, rotation, glm::vec3(1, 1, 0));
	model = glm::scale(model, glm::vec3(4, 4, 1));
	glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));
}

std::vector<Chunk> get_chunks() {
	return chunks;
}