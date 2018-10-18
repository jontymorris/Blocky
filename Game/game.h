#pragma once

#include "renderer.h"
#include "player.h"
#include "chunk.h"

#include <thread>
#include <mutex>

class Game {
public:
	bool running;
	
	Player player;

	std::vector<Chunk> chunks;
	std::thread chunks_thread;
	std::mutex chunks_mutex;

	~Game();

	void setup();
	void update();
	void render();
	
	void key_callback(int key, int action);
	void mouse_callback(double x_pos, double y_pos);
private:
	Renderer renderer;

	void create_chunks();
};