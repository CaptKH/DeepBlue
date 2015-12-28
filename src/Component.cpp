#include <Component.h>

Component::Component(void)
	: entityID(0), type(ComponentType::BASE)
{
}

Component::Component(const unsigned eID, ComponentType t)
	: entityID(eID), type(t)
{
}

Component::~Component(void)
{
}

const unsigned Component::GetEntityID(void)
{
	return entityID;
}