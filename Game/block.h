#pragma once

#include <vector>
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
	Block(int x, int y, int z, BlockMaterial material);
};