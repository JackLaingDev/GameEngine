#ifndef EntityFactory_H 
#define EntityFactory_H

#include <iostream> 

#include "EntityManager.h"

// Class declaration
class EntityFactory {
private:

	EntityManager* em;

public:

	EntityFactory(EntityManager* em);

	static void playerEntity();
	static void testEntity();

};

#endif 
