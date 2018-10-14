#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#define VERT_COUNT 4

struct Face {
	glm::vec3 *vertices;
	glm::vec2 *texture_coords;
	
	Face(){
		vertices = new glm::vec3[VERT_COUNT];
		texture_coords = new glm::vec2[VERT_COUNT];
	}
	
	~Face(){
		delete[] vertices;
		delete[] texture_coords;
	}
	
	//Copy Constructor
	Face(const Face &prev){
		memcpy(vertices, prev.vertices, VERT_COUNT * sizeof(glm::vec3));
		memcpy(texture_coords, prev.texture_coords, VERT_COUNT * sizeof(glm::vec2));
	};
};