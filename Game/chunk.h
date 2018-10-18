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
	Block blocks[MAX_BLOCKS];

	Chunk();
	Chunk(int x, int y, int z);

	void render();
private:
	glm::vec3 chunk_position;
	
	int indice_count;
	bool should_rebuffer, is_setup;
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	unsigned int vao, vbo, ebo;

	void setup();
	void generate_vertices();
	void update_buffers();

	bool is_block_present(glm::vec3 position);
};