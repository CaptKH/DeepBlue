#include <RenderComponent.h>

RenderComponent::RenderComponent(Mesh* m, Material* mat)
{
	type = ComponentType::RENDER;
	mesh = m;
	material = mat;
}

RenderComponent::~RenderComponent(void)
{
	mesh = nullptr;
	material = nullptr;
}

Mesh* RenderComponent::GetMesh(void)
{
	return mesh;
}

Material* RenderComponent::GetMaterial(void)
{
	return material;
}