#include <RenderSystem.h>
#include <RenderComponent.h>

#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

RenderSystem::RenderSystem(void)
{
	eManager = EntityManager::Instance();
}

RenderSystem::~RenderSystem(void)
{
}

void RenderSystem::Update(float dt, float tt) 
{
	std::vector<Entity*> rEntities = eManager->EntitiesWithComponents(ComponentType::RENDER);
	Mesh* mesh;
	Material *material;
	RenderComponent* rComponent;

	for (int i = 0; i < rEntities.size(); i++) {
		rComponent = eManager->GetComponent<RenderComponent>(rEntities[i], ComponentType::RENDER);
		mesh = rComponent->GetMesh();
		material = rComponent->GetMaterial();

		glUseProgram(material->GetProgram());
		glBindVertexArray(mesh->GetVAO());
		glDrawArrays(GL_TRIANGLES, 0, mesh->GetNumVertices());
		glBindVertexArray(0);
	}
}