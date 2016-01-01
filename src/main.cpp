/* Deep Blue Graphics Engine */
/* Created: 12/23/2015       */
/* Author: Kirk Hewitt       */

#include <GLCore.h>

#include <EntityManager.h>
#include <ResourceManager.h>

#include <RenderComponent.h>
#include <TransformComponent.h>

int main() {
	GLCore* core = new GLCore();
	core->Initialize();
	EntityManager* eManager = EntityManager::Instance();
	ResourceManager* rManager = ResourceManager::Instance();
	Entity* e = eManager->Create("Entity");
	eManager->AddComponent(e, new RenderComponent(rManager->GetMesh("Triangle"), rManager->GetMaterial("Standard")));

	core->Run();
	delete core;

	return 0;
}
