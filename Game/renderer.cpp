#include "renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphics_util.h"
#include "game.h"

static unsigned int vao, shader_program;
static unsigned int grass_texture;

// Returns the shader program id
unsigned int get_shader_program() {
	return shader_program;
}

// Sets up the shaders, buffers, and more
void render_setup() {
	// Shaders
	unsigned int vertex_shader = create_shader(GL_VERTEX_SHADER, "shader.vert");
	unsigned int frag_shader = create_shader(GL_FRAGMENT_SHADER, "shader.frag");

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, frag_shader);
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(frag_shader);

	// Textures
	grass_texture = create_texture("grass.png");
	
	// Generate the VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	// Projection matrix
	glm::mat4 ortho = glm::ortho(-8.0f, 8.0f, -4.5f, 4.5f, -5.0f, 5.0f);
	unsigned int ortho_location = glGetUniformLocation(shader_program, "projection");
	glUseProgram(shader_program);
	glUniformMatrix4fv(ortho_location, 1, GL_FALSE, glm::value_ptr(ortho));
}

// Render the game
void render_game() {
	glClear(GL_COLOR_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, grass_texture);

	glUseProgram(shader_program);
	glBindVertexArray(vao);

	// draw all of the chunks
	std::vector<Chunk> chunks = get_chunks();
	for (int i = 0; i < chunks.size(); i++) {
		chunks[i].Draw();
	}
}