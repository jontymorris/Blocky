#include "chunk.h"

// Create the chunk
void Chunk::init(int x, int y, int z) {
	Chunk::x = x;
	Chunk::y = y;
	Chunk::z = z;
	
	// init the blocks
	int index = 0;
	for (int blockX=0; blockX<10; blockX++) {
		for (int blockY=0; blockY<10; blockY++) {
			for (int blockZ=0; blockZ<10; blockZ++) {
				blocks[index].x = blockX + x;
				blocks[index].y = blockY + y;
				blocks[index].z = blockZ + z;
				blocks[index].blockType = Air;
				
				index ++;
			}
		}
	}
}