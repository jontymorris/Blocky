#include "chunk.h"
#include <vector>
#include <map>

Chunk::Chunk() : Chunk::Chunk(0, 0, 0) {};

Chunk::Chunk(int chunk_x, int chunk_y, int chunk_z) {
	chunk_position = glm::vec3(chunk_x, chunk_y, chunk_z);

	vao = 0;
	vbo = 0;
	ebo = 0;
	indice_count = 0;
	is_setup = false;

	// Fill the chunk with cubes
	int index = 0;
	for (int cube_y = 0; cube_y < CHUNK_SIZE; cube_y++) {
		for (int cube_x = 0; cube_x < CHUNK_SIZE; cube_x++) {
			for (int cube_z = 0; cube_z < CHUNK_SIZE; cube_z++) {
				blocks[index] = Block(glm::vec3(chunk_x + cube_x, chunk_y + cube_y, chunk_z + cube_z), Grass);
				index += 1;
			}	
		}
	}

	generate_vertices();
}

void Chunk::setup() {
	is_setup = true;

	// Generate the VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create the buffers
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, MAX_BLOCKS * sizeof(GLfloat) * 6 * 5 * 4, NULL, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MAX_BLOCKS * sizeof(unsigned int) * 36, NULL, GL_DYNAMIC_DRAW);

	// Vertex positon
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glEnableVertexAttribArray(0);

	// Texture coordinate
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);
}

void Chunk::generate_vertices() {
	should_rebuffer = true;
	vertices = std::vector<float>();
	indices = std::vector<unsigned int>();

	// Loop through all of the cubes
	for (int i = 0; i < MAX_BLOCKS; i++) {
		// Check if the block is air
		if (blocks[i].material == Air) {
			continue;
		}

		// Detect the surrounding blocks
		std::map<FaceSide, bool> block_present;
		block_present[Top] = is_block_present(blocks[i].position + glm::vec3(0, 1, 0));
		block_present[Bottom] = is_block_present(blocks[i].position + glm::vec3(0, -1, 0));
		block_present[Left] = is_block_present(blocks[i].position + glm::vec3(-1, 0, 0));
		block_present[Right] = is_block_present(blocks[i].position + glm::vec3(1, 0, 0));
		block_present[Front] = is_block_present(blocks[i].position + glm::vec3(0, 0, -1));
		block_present[Back] = is_block_present(blocks[i].position + glm::vec3(0, 0, 1));

		// Get the cube's faces
		std::vector<Face> faces = blocks[i].faces;

		// Loop through all of the cubes faces
		for (unsigned int j = 0; j < faces.size(); j++) {
			// Check if the face should be rendered
			if (block_present[faces[j].face_side]) {
				continue;
			}

			// Loop through all of the face's vertices
			for (int k = 0; k < 4; k++) {
				// Add the vertices to the total vertices
				vertices.push_back(faces[j].vertices[k].x);
				vertices.push_back(faces[j].vertices[k].y);
				vertices.push_back(faces[j].vertices[k].z);

				vertices.push_back(faces[j].texture_coords[k].x);
				vertices.push_back(faces[j].texture_coords[k].y);
			}

			// Add the indices to the total indices
			int indice_offset = (indices.size() / 6) * 4;
			indices.push_back(indice_offset);
			indices.push_back(indice_offset + 1);
			indices.push_back(indice_offset + 3);
			indices.push_back(indice_offset + 1);
			indices.push_back(indice_offset + 2);
			indices.push_back(indice_offset + 3);
		}
	}
}

void Chunk::update_buffers() {
	should_rebuffer = false;

	glBindVertexArray(vao);

	// Bind the new buffer data
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(GLfloat), &vertices.front());
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices.size() * sizeof(unsigned int), &indices.front());

	indice_count = indices.size();
}

void Chunk::render(){
	if (!is_setup) {
		setup();
	}

	if (should_rebuffer) {
		update_buffers();
	}

	// Draw bound data
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indice_count, GL_UNSIGNED_INT, 0);
}

bool Chunk::is_block_present(glm::vec3 position) {
	for (int i = 0; i < MAX_BLOCKS; i++) {
		if (blocks[i].position == position) {
			return blocks[i].material != Air;
		}
	}

	return false;
}