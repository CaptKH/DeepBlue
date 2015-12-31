#include <Component.h>

Component::Component(void)
{
	type = ComponentType::BASE;
}

Component::~Component(void)
{
}

ComponentType Component::GetType(void)
{
	return type;
}

bool Component::operator == (Component* other)
{
	if (other->GetType() == this->GetType()) return true;
	return false;
}