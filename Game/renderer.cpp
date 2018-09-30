#include "renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphics_util.h"

static unsigned int vao, vbo, ebo, shader_program;
static unsigned int grass_texture;

static std::vector<float> vertices;
static std::vector<unsigned int> indices;

// Returns the shader program id
unsigned int get_shader_program() {
	return shader_program;
}

// Draws a rectangle
void draw_face(Face face) {
	for (int i = 0; i < 4; i++) {
		vertices.push_back(face.vertices[i].x);
		vertices.push_back(face.vertices[i].y);
		vertices.push_back(face.vertices[i].z);

		vertices.push_back(face.texture_coords[i].x);
		vertices.push_back(face.texture_coords[i].y);
	}

	int offset = (indices.size() / 6) * 4;
	indices.push_back(offset);
	indices.push_back(offset + 1);
	indices.push_back(offset + 3);
	indices.push_back(offset + 1);
	indices.push_back(offset + 2);
	indices.push_back(offset + 3);
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

	// VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// EBO
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Vertex positon
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*5, (void*)0);
	glEnableVertexAttribArray(0);

	// Texture coordinate
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float)*3));
	glEnableVertexAttribArray(1);

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

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_DYNAMIC_DRAW);
	//glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(float), &vertices.front());

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_DYNAMIC_DRAW);
	//glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices.size() * sizeof(unsigned int), &indices.front());

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}