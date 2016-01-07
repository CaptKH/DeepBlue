#include <RenderSystem.h>
#include <CameraComponent.h>
#include <RenderComponent.h>
#include <TransformComponent.h>
#include <LightComponent.h>

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
	Mesh* currentMesh = nullptr;
	Material* currentMaterial = nullptr;

	// Get camera
	std::vector<Entity*> cameraEntity = eManager->EntitiesWithComponents(ComponentType::CAMERA);
	TransformComponent* cameraTransform = eManager->GetComponent<TransformComponent>(cameraEntity[0], ComponentType::TRANSFORM);
	CameraComponent* cComponent = eManager->GetComponent<CameraComponent>(cameraEntity[0], ComponentType::CAMERA);
	cComponent->GetCamera()->SetPosition(cameraTransform->translation);

	// Get Light
	std::vector<Entity*> eee  = eManager->EntitiesWithComponents(ComponentType::LIGHT);
	Entity* lightEntity = eee[0];
	Light* l = eManager->GetComponent<LightComponent>(lightEntity, ComponentType::LIGHT)->GetLight();
	TransformComponent* lightTransform = eManager->GetComponent<TransformComponent>(lightEntity, ComponentType::TRANSFORM);
	glm::vec3 lightPos = l->position;

	if (lightTransform) {
		lightPos += lightTransform->translation;
	}
	

	
	for (int i = 0; i < rEntities.size(); i++) {
		rComponent = eManager->GetComponent<RenderComponent>(rEntities[i], ComponentType::RENDER);
		tComponent = eManager->GetComponent<TransformComponent>(rEntities[i], ComponentType::TRANSFORM);
		Mesh* mesh = rComponent->GetMesh();
		Material* material = rComponent->GetMaterial();

		if (material != currentMaterial) {
			currentMaterial = material;
			glUseProgram(currentMaterial->GetProgram());
			glUniformMatrix4fv(material->GetUniform("view"), 1, GL_FALSE, glm::value_ptr(cComponent->GetCamera()->ViewMatrix())); // Camera mat
			glUniformMatrix4fv(material->GetUniform("projection"), 1, GL_FALSE, glm::value_ptr(projectionMat));					  // Projection mat
			glUniform3fv(material->GetUniform("light.position"), 1, glm::value_ptr(lightPos));
			glUniform3fv(material->GetUniform("light.color"), 1, glm::value_ptr(l->color));
			glUniform3fv(material->GetUniform("cameraPos"), 1, glm::value_ptr(cameraTransform->translation));
		}

		if (mesh != currentMesh) {
			currentMesh = mesh;
			if (mesh->GetTexture() != nullptr) {
				glBindTexture(GL_TEXTURE_2D, mesh->GetTexture()->GetTexture()); // Texture
			}
			glBindVertexArray(currentMesh->GetVAO());
		}

		glUniformMatrix4fv(currentMaterial->GetUniform("transform"), 1, GL_FALSE, glm::value_ptr(tComponent->Transformation())); // Model mat
		glUniform3fv(currentMaterial->GetUniform("origin"), 1, glm::value_ptr(mesh->Origin()));									 // Origin

		glDrawElements(GL_TRIANGLES, mesh->NumIndicies(), GL_UNSIGNED_INT, 0);
	}

	glBindVertexArray(0);
}