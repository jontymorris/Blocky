#pragma once

#include <glad/glad.h>

unsigned int create_texture(const char * file_path);

unsigned int create_shader(GLenum shader_type, const char * file_path);