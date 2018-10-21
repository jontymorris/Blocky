#include "renderer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphics_util.h"
#include "constants.h"
#include "game.h"

// Setup the renderer
void Renderer::setup() {
	// Create the shaders
	unsigned int vertex_shader = create_shader(GL_VERTEX_SHADER, "shader.vert");
	unsigned int frag_shader = create_shader(GL_FRAGMENT_SHADER, "shader.frag");

	// Setup the shader program
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, frag_shader);
	glLinkProgram(shader_program);

	// Delete redundant shaders
	glDeleteShader(vertex_shader);
	glDeleteShader(frag_shader);

	glUseProgram(shader_program);

	// Setup textures
	grass_texture = create_texture("grass.png");
	
	// Locate the matrices
	projection_location = glGetUniformLocation(shader_program, "projection");
	view_location = glGetUniformLocation(shader_program, "view");
	model_location = glGetUniformLocation(shader_program, "model");

	// Projection matrix
	projection = glm::perspective(glm::radians(45.0f), WINDOW_WIDTH/WINDOW_HEIGHT, 0.1f, 100.0f);
	glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));

	// View matrix
	view = glm::mat4(1);
	glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));

	// Model matrix
	glm::mat4(1.0);
	glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));

	// Other
	glClearColor(0.3f, 0.4f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

// Render the game
void Renderer::render(Game *game) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Bind the textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, grass_texture);

	// Bind the shader program
	glUseProgram(shader_program);
	
	// Update the camera position
	view = glm::lookAt(game->player.camera.position, game->player.camera.position + game->player.camera.front, game->player.camera.up);
	glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));

	// Draw all of the chunks
	game->chunks_mutex.lock();
	for (unsigned int i = 0; i < game->chunks.size(); i++) {
		float delta_x = abs(game->chunks[i].chunk_position.x - game->player.position.x);
		float delta_z = abs(game->chunks[i].chunk_position.z - game->player.position.z);
		float delta_y = abs(game->chunks[i].chunk_position.y - game->player.position.y);
		float distance = sqrt(pow(delta_x, 2) + pow(delta_z, 2) + pow(delta_y, 2));

		if (distance < RENDER_DISTANCE) {
			game->chunks[i].render();
		}
	}
	game->chunks_mutex.unlock();
}