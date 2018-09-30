#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "renderer.h"
#include "cube.h"

std::vector<Cube> cubes;
unsigned int transform_location;
int rotation;

// Initialize the game
void game_setup() {
	cubes.push_back(Cube(-1, 0, 0));

	for (int i = 0; i < cubes.size(); i++) {
		std::vector<Face> faces = cubes[i].get_faces();
		for (int j = 0; j < faces.size(); j++) {
			draw_face(faces[j]);
		}
	}

	transform_location = glGetUniformLocation(get_shader_program(), "transform");
}

// Game update
void game_update() {
	rotation += 1;

	glm::mat4 trans = glm::mat4(1.0);
	trans = glm::rotate(trans, glm::radians(rotation/5.0f), glm::vec3(0, 0, 1));
	trans = glm::scale(trans, glm::vec3(2, 2, 2));

	glUseProgram(get_shader_program());
	glUniformMatrix4fv(transform_location, 1, GL_FALSE, glm::value_ptr(trans));
}