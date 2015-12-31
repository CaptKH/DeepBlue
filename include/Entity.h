#ifndef ENTITY
#define ENTITY

#include <string>

#include "ComponentLinkedList.h"

class Entity
{
private:
	std::string tag;
	const unsigned ID;
	ComponentLinkedList* components;
	bool isActive;

public:
	Entity(void);
	Entity(std::string t, const unsigned ID);
	~Entity(void);

	std::string GetTag(void);
	const unsigned GetID(void);
	ComponentLinkedList* GetComponents(void);
	bool IsActive();
	void IsActive(bool val);

	bool operator == (Entity* other);
	bool operator == (Entity  other);
};

#endif