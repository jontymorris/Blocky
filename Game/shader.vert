#version 330 core
layout (location=0) in vec3 pos;
layout (location=1) in vec2 coord;

out vec2 tex_coord;

uniform mat4 transform;
uniform mat4 projection;

void main() {
	gl_Position = transform * vec4(pos, 1.0f) * projection;
	tex_coord = coord;
}