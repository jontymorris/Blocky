#pragma once

#include <vector>
#include "face.h"

class Cube {
public:
	Cube(float x, float y, float z);
	std::vector<Face> get_faces();
private:
	glm::vec3 position;
};