#include "cube.h"

Cube::Cube(float x, float y, float z) {
	position = glm::vec3(x, y, z);
}

// Returns all of the cube faces
std::vector<Face> Cube::get_faces() {
	std::vector<Face> faces;

	Face front_face;
	front_face.vertices[0] = glm::vec3(position.x + 1, position.y + 1, position.z);
	front_face.texture_coords[0] = glm::vec2(1, 1);

	front_face.vertices[1] = glm::vec3(position.x + 1, position.y, position.z);
	front_face.texture_coords[1] = glm::vec2(1, 0);

	front_face.vertices[2] = glm::vec3(position.x, position.y, position.z);
	front_face.texture_coords[2] = glm::vec2(0, 0);

	front_face.vertices[3] = glm::vec3(position.x, position.y + 1, position.z);
	front_face.texture_coords[3] = glm::vec2(0, 1);

	faces.push_back(front_face);

	return faces;
}