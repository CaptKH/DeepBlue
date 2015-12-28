#include <Entity.h>

Entity::Entity(void)
	: tag("NULL"), ID(0), isActive(true)
{
}

Entity::Entity(std::string t, const unsigned id)
	: tag(t), ID(id), isActive(true)
{
}

std::string Entity::GetTag(void)
{
	return tag;
}

const unsigned Entity::GetID(void)
{
	return ID;
}

bool Entity::IsActive(void)
{
	return isActive;
}

void Entity::IsActive(bool val)
{
	isActive = val;
}

bool Entity::operator == (Entity* other) 
{
	if (this->ID == other->GetID()) return true;
	return false;
}

bool Entity::operator == (Entity other)
{
	if (this->ID == other.GetID()) return true;
	return false;
}