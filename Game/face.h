#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Face {
	glm::vec3 vertices[4];
	glm::vec2 texture_coords[4];
};