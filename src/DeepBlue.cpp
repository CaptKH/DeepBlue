#include <DeepBlue.h>

// Systems
#include <InputSystem.h>
#include <PhysicsSystem.h>
#include <LightSystem.h>
#include <RenderSystem.h>

// Components
#include <CameraComponent.h>
#include <RenderComponent.h>
#include <PhysicsComponent.h>
#include <TransformComponent.h>
#include <LightComponent.h>

// Testing
#include <random>
#include <time.h>

DeepBlue::DeepBlue(void)
{
}

DeepBlue::~DeepBlue(void)
{
	delete core;
	core = 0;
}

void DeepBlue::Initialize(void)
{
	srand(time(NULL));

	core = new GLCore();
	core->Initialize();

	iManager = InputManager::Instance();
	eManager = EntityManager::Instance();
	sManager = SystemManager::Instance();
	rManager = ResourceManager::Instance();
	// Initialize input callback functions
	iManager->Initialize(core->Window());

	// Create engine systems (order matters!)
	sManager->AddSystem(new InputSystem());
	sManager->AddSystem(new PhysicsSystem());
	sManager->AddSystem(new LightSystem());
	sManager->AddSystem(new RenderSystem());

	// Camera
	Entity* camera = eManager->Create("Camera");
	eManager->AddComponent(camera, new CameraComponent());
	eManager->AddComponent(camera, new TransformComponent());
	eManager->AddComponent(camera, new PhysicsComponent());
	Light* light = new Light();
	light->position = glm::vec3(0.0f, 0.0f, 0.0f);
	light->color = glm::vec3(1.0f, 1.0f, 1.0f);
	light->strength = 0.6f;
	eManager->AddComponent(camera, new LightComponent(light));
	
	// Entities
	Entity* front = eManager->Create("Front");
	eManager->AddComponent(front, new RenderComponent(rManager->GetMesh("Gollum"), rManager->GetMaterial("Standard")));
	eManager->AddComponent(front, new TransformComponent(glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(), glm::vec3(2.0f)));

	Entity* falcon = eManager->Create("Sphere");
	eManager->AddComponent(falcon, new RenderComponent(rManager->GetMesh("Sphere"), rManager->GetMaterial("Texture")));
	eManager->AddComponent(falcon, new TransformComponent(glm::vec3(4.0f, 0.0f, -2.0f), glm::vec3(), glm::vec3(1.1f)));

	Entity* cube = eManager->Create("Cube");
	eManager->AddComponent(cube, new RenderComponent(rManager->GetMesh("Cube"), rManager->GetMaterial("Texture")));
	eManager->AddComponent(cube, new TransformComponent(glm::vec3(0.0f, 3.0f, -2.0f), glm::vec3(), glm::vec3(0.7f)));

	// dt/tt
	float currentTime = glfwGetTime();
	deltaTime = currentTime;
	totalTime = currentTime;
}

void DeepBlue::Run(void)
{
	while (!glfwWindowShouldClose(core->Window())) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();		// Process current frames events & execute necessary callbacks

		float currentTime = glfwGetTime();
		deltaTime = currentTime - totalTime;
		totalTime = currentTime;

		std::vector<Entity*> entities = eManager->EntitiesWithComponents(ComponentType::TRANSFORM);

		for (auto& e : entities) {
			TransformComponent* tComponent = eManager->GetComponent<TransformComponent>(e, ComponentType::TRANSFORM);
			//tComponent->Rotate(1.0f, 0.0f, 0.0f, 1.5f * deltaTime);
		}

		sManager->Update(deltaTime, totalTime);

		glfwSwapBuffers(core->Window());
	}
}