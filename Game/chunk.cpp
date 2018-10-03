#include "chunk.h"
#include <vector>

int indice_count;

Chunk::Chunk() : Chunk::Chunk(0, 0, 0) {};

Chunk::Chunk(int chunk_x, int chunk_y, int chunk_z) {
	position = glm::vec3(chunk_x, chunk_y, chunk_z);

	// Generate the cubes
	int index = 0;
	for (int cube_y = 0; cube_y < CHUNK_SIZE; cube_y++) {
		for (int cube_x = 0; cube_x < CHUNK_SIZE; cube_x++) {
			for (int cube_z = 0; cube_z < CHUNK_SIZE; cube_z++) {
				cubes[index] = Cube(chunk_x + cube_x, chunk_y + cube_y, chunk_z + cube_z);
				index += 1;
			}	
		}
	}

	// Create the buffers
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Vertex positon
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glEnableVertexAttribArray(0);

	// Texture coordinate
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);

	UpdateBuffers();
}

void Chunk::UpdateBuffers() {
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	// Loop through all of the cubes
	for (int i = 0; i < CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE; i++) {
		// Get the cube's faces
		std::vector<Face> faces = cubes[i].get_faces();

		// Loop through all of the cubes faces
		for (int j = 0; j < faces.size(); j++) {
			// Loop through all of the face's vertices
			for (int k = 0; k < 4; k++) {
				vertices.push_back(faces[j].vertices[k].x);
				vertices.push_back(faces[j].vertices[k].y);
				vertices.push_back(faces[j].vertices[k].z);

				vertices.push_back(faces[j].texture_coords[k].x);
				vertices.push_back(faces[j].texture_coords[k].y);
			}

			// Add the indices
			int indice_offset = (indices.size() / 6) * 4;
			indices.push_back(indice_offset);
			indices.push_back(indice_offset + 1);
			indices.push_back(indice_offset + 3);
			indices.push_back(indice_offset + 1);
			indices.push_back(indice_offset + 2);
			indices.push_back(indice_offset + 3);
		}
	}
	
	// Bind the data
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_DYNAMIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_DYNAMIC_DRAW);

	indice_count = indices.size();
}

void Chunk::Draw() {
	// Bind buffers
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Draw bound data
	glDrawElements(GL_TRIANGLES, indice_count, GL_UNSIGNED_INT, 0);
}