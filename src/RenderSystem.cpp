#include <RenderSystem.h>
#include <RenderComponent.h>
#include <TransformComponent.h>

#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include <glm/gtc/type_ptr.hpp>

RenderSystem::RenderSystem(void)
{
	eManager = EntityManager::Instance();
}

RenderSystem::~RenderSystem(void)
{
}

void RenderSystem::Update(float dt, float tt) 
{
	std::vector<Entity*> rEntities = eManager->EntitiesWithComponents(ComponentType::RENDER, ComponentType::TRANSFORM);
	Mesh* mesh;
	Material *material;
	RenderComponent* rComponent;
	TransformComponent* tComponent;

	for (int i = 0; i < rEntities.size(); i++) {
		rComponent = eManager->GetComponent<RenderComponent>(rEntities[i], ComponentType::RENDER);
		tComponent = eManager->GetComponent<TransformComponent>(rEntities[i], ComponentType::TRANSFORM);

		mesh = rComponent->GetMesh();
		material = rComponent->GetMaterial();

		glUseProgram(material->GetProgram());
		glUniformMatrix4fv(material->GetTransformUniform(), 1, GL_FALSE, glm::value_ptr(tComponent->Transformation()));
		glBindVertexArray(mesh->GetVAO());
		glDrawElements(GL_TRIANGLES, mesh->NumIndicies(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}