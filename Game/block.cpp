#include "block.h"

Block::Block() : Block::Block(0, 0, 0, Grass) {}

Block::Block(int x, int y, int z, BlockMaterial material) {
	position = glm::vec3(x, y, z);
	Block::material = material;
	
	faces.reserve(FACE_COUNT);
	
	// Initialize all of the cube faces
	glm::vec2 tex_coords[] = {
		glm::vec2(1, 1),
		glm::vec2(1, 0),
		glm::vec2(0, 0),
		glm::vec2(0, 1)
	};

	Face front_face;
	front_face.face_side = Front;
	front_face.vertices[0] = glm::vec3(position.x + 1, position.y + 1, position.z);
	front_face.vertices[1] = glm::vec3(position.x + 1, position.y, position.z);
	front_face.vertices[2] = glm::vec3(position.x, position.y, position.z);
	front_face.vertices[3] = glm::vec3(position.x, position.y + 1, position.z);
	memcpy(front_face.texture_coords, tex_coords, 4 * sizeof(glm::vec2));

	Face back_face;
	back_face.face_side = Back;
	back_face.vertices[0] = glm::vec3(position.x + 1, position.y + 1, position.z + 1);
	back_face.vertices[1] = glm::vec3(position.x + 1, position.y, position.z + 1);
	back_face.vertices[2] = glm::vec3(position.x, position.y, position.z + 1);
	back_face.vertices[3] = glm::vec3(position.x, position.y + 1, position.z + 1);
	memcpy(back_face.texture_coords, tex_coords, 4 * sizeof(glm::vec2));

	Face top_face;
	top_face.face_side = Top;
	top_face.vertices[0] = glm::vec3(position.x + 1, position.y + 1, position.z + 1);
	top_face.vertices[1] = glm::vec3(position.x + 1, position.y + 1, position.z);
	top_face.vertices[2] = glm::vec3(position.x, position.y + 1, position.z);
	top_face.vertices[3] = glm::vec3(position.x, position.y + 1, position.z + 1);
	memcpy(top_face.texture_coords, tex_coords, 4 * sizeof(glm::vec2));

	Face bottom_face;
	bottom_face.face_side = Bottom;
	bottom_face.vertices[0] = glm::vec3(position.x + 1, position.y, position.z + 1);
	bottom_face.vertices[1] = glm::vec3(position.x + 1, position.y, position.z);
	bottom_face.vertices[2] = glm::vec3(position.x, position.y, position.z);
	bottom_face.vertices[3] = glm::vec3(position.x, position.y, position.z + 1);
	memcpy(bottom_face.texture_coords, tex_coords, 4 * sizeof(glm::vec2));

	Face left_face;
	left_face.face_side = Left;
	left_face.vertices[0] = glm::vec3(position.x, position.y + 1, position.z + 1);
	left_face.vertices[1] = glm::vec3(position.x, position.y, position.z + 1);
	left_face.vertices[2] = glm::vec3(position.x, position.y, position.z);
	left_face.vertices[3] = glm::vec3(position.x, position.y + 1, position.z);
	memcpy(left_face.texture_coords, tex_coords, 4 * sizeof(glm::vec2));

	Face right_face;
	right_face.face_side = Right;
	right_face.vertices[0] = glm::vec3(position.x + 1, position.y + 1, position.z + 1);
	right_face.vertices[1] = glm::vec3(position.x + 1, position.y, position.z + 1);
	right_face.vertices[2] = glm::vec3(position.x + 1, position.y, position.z);
	right_face.vertices[3] = glm::vec3(position.x + 1, position.y + 1, position.z);
	memcpy(right_face.texture_coords, tex_coords, 4 * sizeof(glm::vec2));

	faces.push_back(front_face);
	faces.push_back(back_face);
	faces.push_back(top_face);
	faces.push_back(bottom_face);
	faces.push_back(left_face);
	faces.push_back(right_face);
}