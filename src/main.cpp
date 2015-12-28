/* Deep Blue Graphics Engine */
/* Created: 12/23/2015       */
/* Author: Kirk Hewitt       */

#include <GLCore.h>
#include <ResourceManager.h>

#include <EntityManager.h>

int main() {
	GLCore* core = new GLCore();
	EntityManager* eManager = EntityManager::Instance();

	Entity* e1 = eManager->Create("e1");
	Entity* e2 = eManager->Create("e2");
	Entity* e3 = eManager->Create("e3");
	Entity* e4 = eManager->Create("e4");

	eManager->Destroy(e3);
	eManager->Entities()->CleanUp();
	core->Initialize();
	core->Run();
	delete core;

	return 0;
}