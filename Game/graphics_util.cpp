#include "graphics_util.h"
#include "file_util.h"
#include "stb_image.h"

// Creates a texture and returns the id
unsigned int create_texture(std::string file_path) {
	unsigned int texture_id;
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	int width, height, nr_channels;
	unsigned char *data = stbi_load("grass.png", &width, &height, &nr_channels, 0);

	if (!data) {
		printf("Failed to load in texture %s\n", file_path.c_str());
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);

	return texture_id;
}

// Creates a shader and returns the shader id
unsigned int create_shader(GLenum shader_type, std::string file_path) {
	unsigned int shader_id = glCreateShader(shader_type);

	std::string shader_content = read_file(file_path);
	GLchar const *shader_source = shader_content.c_str();

	glShaderSource(shader_id, 1, &shader_source, NULL);
	glCompileShader(shader_id);

	int success;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
	if (!success) {
		char log[512];
		glGetShaderInfoLog(shader_id, 512, NULL, log);
		printf("Shader failed!\n");
		printf("%s\n", log);
	}

	return shader_id;
}