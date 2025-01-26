#ifndef CollisionManager_H 
#define CollisionManager_H

#include <iostream> 
#include <vector>

#include "EventManager.h"
#include "EntityManager.h"

// Class declaration
class CollisionManager {
private:

	std::vector<Entity> collisionEntities;
	EventManager* eventManager;
	EntityManager* entityManager;

public:

	CollisionManager(EventManager* eventManager, EntityManager* entityManager);

	void collisionCheck();

};

#endif 
