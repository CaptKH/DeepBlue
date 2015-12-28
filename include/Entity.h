#ifndef ENTITY
#define ENTITY

#include <string>

class Entity
{
private:
	std::string tag;
	const unsigned ID;

public:
	Entity(void);
	Entity(std::string t, const unsigned ID);

	std::string GetTag(void);
	const unsigned GetID(void);

	bool operator == (Entity* other);
	bool operator == (Entity  other);
};

#endif