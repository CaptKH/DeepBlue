#include <RenderSystem.h>
#include <CameraComponent.h>
#include <RenderComponent.h>
#include <TransformComponent.h>

#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <GLM\gtc\matrix_transform.hpp>

RenderSystem::RenderSystem(void)
{
	eManager = EntityManager::Instance();
	projectionMat = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
}

RenderSystem::~RenderSystem(void)
{
}

void RenderSystem::Update(float dt, float tt) 
{
	std::vector<Entity*> rEntities = eManager->EntitiesWithComponents(ComponentType::RENDER, ComponentType::TRANSFORM);
	RenderComponent* rComponent;
	TransformComponent* tComponent;

	// Get camera
	std::vector<Entity*> cameraEntity = eManager->EntitiesWithComponents(ComponentType::CAMERA);
	TransformComponent* cameraTransform = eManager->GetComponent<TransformComponent>(cameraEntity[0], ComponentType::TRANSFORM);
	CameraComponent* cComponent = eManager->GetComponent<CameraComponent>(cameraEntity[0], ComponentType::CAMERA);

	cComponent->GetCamera()->SetPosition(cameraTransform->translation);
	Mesh* currentMesh = nullptr;
	Material* currentMaterial = nullptr;

	for (int i = 0; i < rEntities.size(); i++) {
		rComponent = eManager->GetComponent<RenderComponent>(rEntities[i], ComponentType::RENDER);
		tComponent = eManager->GetComponent<TransformComponent>(rEntities[i], ComponentType::TRANSFORM);
		Mesh* mesh = rComponent->GetMesh();
		Material* material = rComponent->GetMaterial();

		if (material != currentMaterial) {
			currentMaterial = material;
			glUseProgram(currentMaterial->GetProgram());
			glUniformMatrix4fv(material->GetViewUniform(), 1, GL_FALSE, glm::value_ptr(cComponent->GetCamera()->ViewMatrix()));
			glUniformMatrix4fv(material->GetProjectionUniform(), 1, GL_FALSE, glm::value_ptr(projectionMat));
		}

		glm::vec3 origin = mesh->Origin();
		glUniformMatrix4fv(material->GetTransformUniform(), 1, GL_FALSE, glm::value_ptr(tComponent->Transformation()));
		glUniform3fv(material->GetOriginUniform(), 1, glm::value_ptr(origin));

		if (mesh != currentMesh) {
			currentMesh = mesh;
			glBindVertexArray(currentMesh->GetVAO());
		}
		glDrawElements(GL_TRIANGLES, mesh->NumIndicies(), GL_UNSIGNED_INT, 0);
	}

	glBindVertexArray(0);
}