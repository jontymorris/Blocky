#pragma once

#include "world.h"
#include <glad/glad.h>
#include <string>

class Renderer {
public:
	GLuint shaderProgram;
	
	void init();
	void clear();
	void renderWorld(const World world);
	void checkError();
private:
	void setupShaderProgram();
	GLuint setupShader(std::string shaderName, GLenum shaderType);
};