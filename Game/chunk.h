#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include "cube.h"

#define CHUNK_SIZE 2
#define MAX_CUBES CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE

class Chunk {
public:
	Chunk();
	Chunk(int x, int y, int z);
	Cube cubes[MAX_CUBES];
	void update_buffers();
	void render();
private:
	int indice_count;
	unsigned int vbo, ebo;
	glm::vec3 position;
};