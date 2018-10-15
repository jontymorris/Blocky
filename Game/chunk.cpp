#include "chunk.h"
#include <vector>

Chunk::Chunk() : Chunk::Chunk(0, 0, 0) {};

Chunk::Chunk(int chunk_x, int chunk_y, int chunk_z) {
	position = glm::vec3(chunk_x, chunk_y, chunk_z);

	// Fill the chunk with cubes
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
	glBufferData(GL_ARRAY_BUFFER, MAX_CUBES*sizeof(GLfloat)*6*5*4, NULL, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MAX_CUBES*sizeof(unsigned int)*36, NULL, GL_DYNAMIC_DRAW);

	// Vertex positon
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glEnableVertexAttribArray(0);

	// Texture coordinate
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);

	update_buffers();
}

void Chunk::update_buffers() {
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	// Loop through all of the cubes
	for (int i = 0; i < MAX_CUBES; i++) {
		// Get the cube's faces
		std::vector<Face> faces = cubes[i].faces;

		// Loop through all of the cubes faces
		for (int j = 0; j < faces.size(); j++) {
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
	
	// Bind the new buffer data
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(GLfloat), &vertices.front());

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices.size() * sizeof(unsigned int), &indices.front());

	indice_count = indices.size();
}

void Chunk::render(){
	// Bind buffers
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Draw bound data
	glDrawElements(GL_TRIANGLES, indice_count, GL_UNSIGNED_INT, 0);
}