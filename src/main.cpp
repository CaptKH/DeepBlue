/* Deep Blue Graphics Engine */
/* Created: 12/23/2015       */
/* Author: Kirk Hewitt       */

#include <GLCore.h>
#include <ResourceManager.h>

#include <LinkedList.h>

int main() {
	GLCore* core = new GLCore();
	ResourceManager* rManager = ResourceManager::Instance();
	core->Initialize();
	rManager->GenerateMeshes();
	rManager->GenerateShaders();
	core->Run();
	delete core;

	return 0;
}