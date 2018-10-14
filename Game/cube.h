#pragma once

#include <vector>
#include "face.h"

#define FACE_COUNT 6

class Cube {
public:
	Cube();
	Cube(float x, float y, float z);
	std::vector<Face> faces;
private:
	glm::vec3 position;
};