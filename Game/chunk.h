#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include "cube.h"

#define CHUNK_SIZE 16

class Chunk {
public:
	Chunk();
	Chunk(int x, int y, int z);
	void UpdateBuffers();
	void Draw();
private:
	unsigned int vbo, ebo;
	glm::vec3 position;
	Cube cubes[CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE];
};