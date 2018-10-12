#include "cube.h"

Cube::Cube() : Cube::Cube(0, 0, 0) {}

Cube::Cube(float x, float y, float z) {
	position = glm::vec3(x, y, z);
}

// Returns all of the cube faces
std::vector<Face> Cube::get_faces() {
	std::vector<Face> faces;

	using namespace glm;
	vec3 verts[] = {
		vec3(position.x + 1, position.y + 1, position.z),
		vec3(position.x + 1, position.y, position.z),
		vec3(position.x, position.y, position.z),
		vec3(position.x, position.y + 1, position.z)
	};
	
	vec2 texCoords[] = {
		vec2(1, 1),
		vec2(1, 0),
		vec2(0, 0),
		vec2(0, 1)
	};
	
	Face front_face;
	memcpy(&front_face.vertices, &verts, 4 * sizeof(vec3));
	memcpy(&front_face.texture_coords, &texCoords, 4 * sizeof(vec2));

	faces.push_back(front_face);

	return faces;
}