#pragma once

enum BlockType {
	Air, Grass
};

struct Block {
	int x = 0;
	int y = 0;
	int z = 0;
	
	BlockType blockType = Air;
};