#include "world.h"

// Create the world
void World::init() {
	for (int i=0; i<10; i++) {
		chunks[i].init(0, 0, 0);
	}
}