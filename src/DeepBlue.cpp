#include <DeepBlue.h>

// Systems
#include <RenderSystem.h>

// Components
#include <RenderComponent.h>
#include <TransformComponent.h>

DeepBlue::DeepBlue(void)
{
}

DeepBlue::~DeepBlue(void)
{
}

void DeepBlue::Initialize(void)
{
	core = new GLCore();
	core->Initialize();

	iManager = InputManager::Instance();
	eManager = EntityManager::Instance();
	sManager = SystemManager::Instance();
	cManager = CameraManager::Instance();
	rManager = ResourceManager::Instance();
	// Initialize input callback functions
	iManager->Initialize(core->Window());

	test = eManager->Create("Test");

	Entity* test2 = eManager->Create("Test2");
	eManager->AddComponent(test2, new RenderComponent(rManager->GetMesh("Suzanne"), rManager->GetMaterial("Standard")));
	eManager->AddComponent(test2, new TransformComponent(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(), glm::vec3(0.5f)));


	sManager->AddSystem(new RenderSystem());
}

void DeepBlue::Run(void)
{
	while (!glfwWindowShouldClose(core->Window())) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();		// Process current frames events & execute necessary callbacks

		eManager->GetComponent<TransformComponent>(eManager->Get("Test2"), ComponentType::TRANSFORM)->Rotate(1.0f, 1.0f, 0.5f, 0.001f);

		sManager->Update(0, 0);

		glfwSwapBuffers(core->Window());
	}

	glfwTerminate();
}