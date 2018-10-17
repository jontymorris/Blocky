#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#define VERT_COUNT 4

enum FaceSide {
	Top, Bottom, Left, Right, Front, Back
};

struct Face {
	FaceSide face_side;

	glm::vec3 *vertices;
	glm::vec2 *texture_coords;
	
	Face() {
		vertices = new glm::vec3[VERT_COUNT];
		texture_coords = new glm::vec2[VERT_COUNT];
	}
	
	~Face() {
		//delete[] vertices;
		//delete[] texture_coords;
	}
};