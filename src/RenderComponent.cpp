#include <RenderComponent.h>

RenderComponent::RenderComponent(void)
{
	Component();
	type = ComponentType::RENDER;
}

RenderComponent::RenderComponent(const unsigned eID, ComponentType t)
{
	Component(eID, t);
}

Mesh* RenderComponent::GetMesh(void)
{
	return mesh;
}

Material* RenderComponent::GetMaterial(void)
{
	return material;
}