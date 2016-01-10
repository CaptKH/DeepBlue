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
	// Get entities
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
	
	for (int i = 0; i < rEntities.size(); i++) {
		rComponent = eManager->GetComponent<RenderComponent>(rEntities[i], ComponentType::RENDER);
		tComponent = eManager->GetComponent<TransformComponent>(rEntities[i], ComponentType::TRANSFORM);
		Mesh* mesh = rComponent->GetMesh();
		Material* material = rComponent->GetMaterial();
		ShaderProgram* shaderProgram = material->GetProgram();

		// Change current material and set per material data
		if (material != currentMaterial) {
			currentMaterial = material;
			glUseProgram(shaderProgram->program);
			shaderProgram->SetVec3("cameraPos", cameraTransform->translation);			  // Camera position
			shaderProgram->SetMat4("view", cComponent->GetCamera()->ViewMatrix(), false); // Camera mat
			shaderProgram->SetMat4("projection", projectionMat, false);					  // Projection mat
			shaderProgram->SetVec3("light.position", l->position);		// Light position
			shaderProgram->SetVec3("light.color", l->color);			// Light color
			shaderProgram->SetFloat("light.strength", l->strength);		// Light strength
		}

		// Change mesh & texture if new entity
		if (mesh != currentMesh) {
			currentMesh = mesh;
			glBindTexture(GL_TEXTURE_2D, material->GetTexture("Container2")); // Texture
			glBindVertexArray(currentMesh->GetVAO());
		}

		// Entity specific
		shaderProgram->SetMat4("transform", tComponent->Transformation(), false);
		shaderProgram->SetMat4("normalMatrix", glm::inverse(tComponent->Transformation()), true);
		shaderProgram->SetVec3("origin", mesh->Origin());

		glDrawElements(GL_TRIANGLES, mesh->NumIndicies(), GL_UNSIGNED_INT, 0);
	}

	glBindVertexArray(0);
}