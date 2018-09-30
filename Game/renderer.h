#pragma once

#include <string>
#include <vector>
#include <glad/glad.h>
#include "face.h"

void render_setup();
void render_game();

void draw_face(Face face);

unsigned int create_shader(GLenum shader_type, std::string file_path);
unsigned int get_shader_program();