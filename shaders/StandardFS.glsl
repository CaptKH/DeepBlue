#version 330 core

in vec3 worldPos;
in vec3 outNormal;
in vec3 outColor;
in vec2 outUV;

out vec4 color;

struct Light 
{
	vec3 position;
	vec3 color;
};

uniform Light light;
uniform vec3  cameraPos;

void main()
{
	// Ambient lighting
	vec3 ambientLight = light.color * 0.3f;

	// Diffuse lighting
	vec3 norm = normalize(outNormal);
	vec3 lightDir = normalize(light.position - worldPos);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuseLight = diff * light.color;

	// Specular lighting
	vec3 viewDir = normalize(cameraPos - worldPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specularLight = spec * light.color * 0.5f;

	vec3 finalColor = (ambientLight + diffuseLight + specularLight) * outColor;
    color = vec4(finalColor, 1.0f);
}