#ifndef RENDER_COMPONENT
#define RENDER_COMPONENT

#include "Component.h"
#include "Mesh.h"
#include "Material.h"

class RenderComponent : public Component
{
private:
	Mesh* mesh;
	Material* material;

public:
	RenderComponent(Mesh* m, Material* mat);
	virtual ~RenderComponent(void);

	Mesh* GetMesh(void);
	Material* GetMaterial(void);
};

#endif