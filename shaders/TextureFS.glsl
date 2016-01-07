#version 330 core

in vec3 outColor;
in vec2 outUV;

out vec4 color;

uniform sampler2D objTexture;

void main()
{
    color = texture(objTexture, outUV);
}