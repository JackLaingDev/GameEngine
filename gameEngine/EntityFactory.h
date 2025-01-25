#ifndef EntityFactory_H 
#define EntityFactory_H

#include <iostream> 
#include <SFML/Graphics.hpp>

#include "EntityManager.h"
#include "Component.h"

// Class declaration
class EntityFactory {
private:

	EntityManager* em;

public:

	EntityFactory(EntityManager* em);

	void playerEntity(int id);
	void testEntity(int id);

};

#endif 
