#include <GLFW/glfw3.h>

class Window {
public:
	int windowWidth;
	int windowHeight;
	GLFWwindow* window;

	void init();
	void close();
	bool shouldWindowClose();
	void pollEvents();
	void swapBuffers();
};