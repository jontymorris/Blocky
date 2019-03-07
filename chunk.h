#pragma once

#include "block.h"

class Chunk {
public:
	int x;
	int y;
	int z;
	
	Block blocks[1000];
	
	void init(int chunkX, int chunkY, int chunkZ);
};