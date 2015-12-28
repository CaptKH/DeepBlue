/* Deep Blue Graphics Engine */
/* Created: 12/23/2015       */
/* Author: Kirk Hewitt       */

#include <GLCore.h>
#include <ResourceManager.h>

#include <EntityManager.h>

int main() {
	GLCore* core = new GLCore();
	core->Initialize();
	core->Run();
	delete core;

	return 0;
}