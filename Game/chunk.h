#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include "cube.h"

class Chunk {
public:
	Chunk();
	Chunk(int x, int y, int z);
	void UpdateBuffers();
	void Draw();
private:
	unsigned int vbo, ebo;
	glm::vec3 position;
	Cube cubes[16 * 16 * 16];
};