#ifndef RENDER_COMPONENT
#define RENDER_COMPONENT

#include "Component.h"
#include "Mesh.h"
#include "Material.h"

class RenderComponent : protected Component
{
private:
	Mesh* mesh;
	Material* material;

public:
	RenderComponent(void);
	RenderComponent(const unsigned eID, ComponentType t);

	Mesh* GetMesh(void);
	Material* GetMaterial(void);
};

#endif