#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <vector>
#include "block.h"

#define CHUNK_SIZE 4
#define LAYER_SIZE CHUNK_SIZE * CHUNK_SIZE
#define MAX_BLOCKS CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE

class Chunk {
public:
	glm::vec3 chunk_position;
	Block blocks[MAX_BLOCKS];

	Chunk();
	Chunk(int x, int y, int z);

	void setup();
	void render();
private:
	bool should_rebuffer, is_setup;
	int indice_count;
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	unsigned int vao, vbo, ebo;

	void generate_vertices();
	void update_buffers();

	bool is_block_present(glm::vec3 position);
};