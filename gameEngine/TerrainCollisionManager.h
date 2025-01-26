#ifndef TerrainCollisionManager_H 
#define TerrainCollisionManager_H

#include <iostream> 
#include <vector>

#include "EventManager.h"
#include "EntityManager.h"

// Class declaration
class TerrainCollisionManager {
private:

	EventManager* eventManager;
	EntityManager* entityManager;

public:

	TerrainCollisionManager(EventManager* eventManager, EntityManager* entityManager);

	void terrainCollisionCheck();

};

#endif 
