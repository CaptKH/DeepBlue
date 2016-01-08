#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 uv;

uniform vec3 origin;
uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 normalMatrix;

out vec3 worldPos;
out vec3 outNormal;
out vec3 outColor;
out vec2 outUV;

void main()
{
	gl_Position = projection * view * transform * vec4(position - origin, 1.0f);
	worldPos = vec3(transform * vec4(position, 1.0f));
	outNormal = mat3(normalMatrix) * normal;
	outColor = color;
	outUV = uv;
}