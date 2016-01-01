#include <System.h>

System::System(void)
{
	eManager = EntityManager::Instance();
}

System::~System(void)
{

}

void System::Update(float dt, float tt)
{
	printf(" ");
}