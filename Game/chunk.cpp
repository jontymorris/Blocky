#include "chunk.h"
#include <vector>

int indice_count;

Chunk::Chunk() : Chunk::Chunk(0, 0, 0) {}

Chunk::Chunk(int x, int y, int z) {
	position = glm::vec3(x, y, z);

	// Fill the chunk with blocks
	for (int i = 0; i < 16; i++) { // x
		for (int j = 0; j < 16; j++) { // y
			for (int k = 0; k < 16; k++) { // z
				cubes[i*j*k] = Cube(x+i, y=j, z+k);
			}
		}
	}

	// Generate the buffers
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	UpdateBuffers();
}

void Chunk::UpdateBuffers() {
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	// Loop through all the cubes'
	for (int i = 0; i < 16 * 16 * 16; i++) {
		std::vector<Face> faces = cubes[i].get_faces();

		// Loop through all of the cube's faces
		for (int j = 0; j < faces.size(); j++) {
			// Add all of the cube's faces to the vertices
			for (int k = 0; k < 4; k++) {
				vertices.push_back(faces[j].vertices[k].x);
				vertices.push_back(faces[j].vertices[k].y);
				vertices.push_back(faces[j].vertices[k].z);

				vertices.push_back(faces[j].texture_coords[k].x);
				vertices.push_back(faces[j].texture_coords[k].y);
			}

			// Add the cube's faces indices
			int offset = (indices.size() / 6) * 4;
			indices.push_back(offset);
			indices.push_back(offset + 1);
			indices.push_back(offset + 3);
			indices.push_back(offset + 1);
			indices.push_back(offset + 2);
			indices.push_back(offset + 3);
		}
	}

	indice_count = indices.size();

	// Update the VBO vertices
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_DYNAMIC_DRAW);

	// Update the EBO indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_DYNAMIC_DRAW);

	// Unbind the buffers
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Chunk::Draw() {
	// Bind the chunk's buffers
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glDrawElements(GL_TRIANGLES, indice_count, GL_UNSIGNED_INT, 0);

	// Unbind buffers
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}