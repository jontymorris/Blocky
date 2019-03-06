#include <glad/glad.h>
#include <string>

class Renderer {
public:
	GLuint shaderProgram;
	
	void init();
	void clear();
	void draw();
	void checkError();
private:
	void setupShaderProgram();
	GLuint setupShader(std::string shaderName, GLenum shaderType);
};