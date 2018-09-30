#pragma once

#include <glad/glad.h>
#include <string>

unsigned int create_texture(std::string file_path);

unsigned int create_shader(GLenum shader_type, std::string file_path);