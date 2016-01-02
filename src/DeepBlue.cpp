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

	eManager = EntityManager::Instance();
	sManager = SystemManager::Instance();
	rManager = ResourceManager::Instance();

	test = eManager->Create("Test");
	eManager->AddComponent(test, new RenderComponent(rManager->GetMesh("Triangle"), rManager->GetMaterial("Standard")));
	eManager->AddComponent(test, new TransformComponent());

	sManager->AddSystem(new RenderSystem());
}

void DeepBlue::Run(void)
{
	while (!glfwWindowShouldClose(core->Window())) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();		// Process current frames events & execute necessary callbacks

		Entity* e = eManager->Get("Test");
		TransformComponent* tComponent = eManager->GetComponent<TransformComponent>(e, ComponentType::TRANSFORM);
		tComponent->Rotate(0, 1, 1, 0.005);

		sManager->Update(0, 0);

		glfwSwapBuffers(core->Window());
	}

	glfwTerminate();
}