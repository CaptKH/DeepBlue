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
	RenderComponent(void);
	virtual ~RenderComponent(void);

	Mesh* GetMesh(void);
	Material* GetMaterial(void);

	bool operator == (Component& other);
};

#endif