#pragma once

#include <vector>
#include <glm/vec3.hpp>
#include "face.h"

#define FACE_COUNT 6

enum BlockMaterial
{
	Grass,
	Air
};

class Block {
public:
	BlockMaterial material;
	glm::vec3 position;

	std::vector<Face> faces;

	Block();
	Block(glm::vec3 position, BlockMaterial material);
};