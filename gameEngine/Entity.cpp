#include "Entity.h"    // Include the corresponding header file

Entity::Entity(int id)
{
	this->id = id;
}

Entity::~Entity()
{
}

int Entity::getId()
{
	return id;
}
