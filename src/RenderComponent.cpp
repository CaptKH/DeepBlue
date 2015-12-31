#include <RenderComponent.h>

RenderComponent::RenderComponent(void)
{
	type = ComponentType::RENDER;
}

RenderComponent::~RenderComponent(void)
{

}

Mesh* RenderComponent::GetMesh(void)
{
	return mesh;
}

Material* RenderComponent::GetMaterial(void)
{
	return material;
}

bool RenderComponent::operator == (Component& other)
{
	if (this->type == other.GetType()) return true;
	return false;
}