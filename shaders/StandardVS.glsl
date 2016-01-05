#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 origin;

out vec3 outColor;

void main()
{
	gl_Position = projection * view * transform * vec4(position - origin, 1.0f);
	outColor = color;
}