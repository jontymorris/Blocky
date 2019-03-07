#pragma once

#include "chunk.h"

class World {
public:
	Chunk chunks[10];

	void init();
};