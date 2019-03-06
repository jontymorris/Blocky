#include "renderer.h"
#include "file_util.h"
#include <iostream>

// Setup the OpenGL renderer
void Renderer::init() {
	// load the bindings
	if (!gladLoadGL()) {
		std::cout << "Failed to load OpenGL" << std::endl;
	}
	
	// get OpenGL ready for use
	glViewport(0, 0, 1280, 720);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	
	setupShaderProgram();
}

// Sets up the shader program and its shaders
void Renderer::setupShaderProgram() {
	// create program and load shaders
	shaderProgram = glCreateProgram();
	
	GLuint vertexShader = setupShader("../shader.vert", GL_VERTEX_SHADER);
	GLuint fragmentShader = setupShader("../shader.frag", GL_FRAGMENT_SHADER);
	
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	
	glLinkProgram(shaderProgram);
	
	// check for errors
	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Program error: " << infoLog << std::endl;
	} else {
		std::cout << "Program linked successfully" << std::endl;
	}
	
	glUseProgram(shaderProgram);
	
	// delete redundant shaders
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
}

// Clears the frame
void Renderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

// Draw the game
void Renderer::draw() {
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

// Checks if there were any errors
void Renderer::checkError() {
	int error = glGetError();
	
	if (error != 0) {
		std::cout << "OpenGL error: " << error << std::endl;
	}
}

// Sets up a shader and returns its ID
GLuint Renderer::setupShader(std::string shaderName, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);
	
	std::string shaderContent = loadFile(shaderName);
	const char* source = shaderContent.c_str();
	
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	
	// check for errors
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Shader error: " << infoLog << std::endl;
	} else {
		std::cout << shaderName << " compiled successfully" << std::endl;
	}
	
	return shader;
}