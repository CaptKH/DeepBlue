#include <RenderSystem.h>
#include <RenderComponent.h>
#include <TransformComponent.h>

#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include <glm/gtc/type_ptr.hpp>

#include <CameraManager.h>

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
	RenderComponent* rComponent;
	TransformComponent* tComponent;
	Mesh* currentMesh;
	Material* currentMaterial;

	for (int i = 0; i < rEntities.size(); i++) {
		rComponent = eManager->GetComponent<RenderComponent>(rEntities[i], ComponentType::RENDER);
		tComponent = eManager->GetComponent<TransformComponent>(rEntities[i], ComponentType::TRANSFORM);

		Mesh* mesh = rComponent->GetMesh();
		Material* material = rComponent->GetMaterial();

		glUseProgram(material->GetProgram());
		glUniformMatrix4fv(material->GetTransformUniform(), 1, GL_FALSE, glm::value_ptr(tComponent->Transformation()));
		glUniformMatrix4fv(material->GetViewUniform(), 1, GL_FALSE, glm::value_ptr(CameraManager::Instance()->GetCamera()->ViewMatrix()));
		glBindVertexArray(mesh->GetVAO());
		glDrawElements(GL_TRIANGLES, mesh->NumIndicies(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}