#pragma once

#include <vector>
#include "face.h"

#define FACE_COUNT 1

class Cube {
public:
	Cube();
	Cube(float x, float y, float z);
	std::vector<Face> get_faces();
private:
	glm::vec3 position;
};