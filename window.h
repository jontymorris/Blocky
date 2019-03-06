#include <GLFW/glfw3.h>

class Window {
public:
	int windowWidth;
	int windowHeight;
	GLFWwindow* window;

	void init();
	void close();
	void pollEvents();
	void swapBuffers();
	bool shouldWindowClose();
	double getTime();
};