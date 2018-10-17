#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include "block.h"

#define CHUNK_SIZE 4
#define LAYER_SIZE CHUNK_SIZE * CHUNK_SIZE
#define MAX_BLOCKS CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE

class Chunk {
public:
	Block blocks[MAX_BLOCKS];

	Chunk();
	Chunk(int x, int y, int z);

	void update_buffers();
	void render();
private:
	int indice_count;
	unsigned int vao, vbo, ebo;

	glm::vec3 chunk_position;

	bool is_block_present(glm::vec3 position);
};