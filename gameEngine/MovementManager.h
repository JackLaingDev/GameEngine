#ifndef MovementManager_H 
#define MovementManager_H

#include <iostream> 

#include "EntityManager.h"
#include "EventManager.h"

// Class declaration
class MovementManager {
private:

	EntityManager* entityManager;

public:

	MovementManager(EntityManager* entityManager);

	void move(Event& event);

};

#endif 
