#include "renderer.h"

class Game {
public:
	bool isRunning;
	Renderer renderer;

	void init();
	void update();
	void render();
	void close();
};