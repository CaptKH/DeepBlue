/* Deep Blue Graphics Engine */
/* Created: 12/23/2015       */
/* Author: Kirk Hewitt       */

#include <DeepBlue.h>

int main() {
	DeepBlue* engine = new DeepBlue();
	engine->Initialize();
	engine->Run();

	delete engine;
}
