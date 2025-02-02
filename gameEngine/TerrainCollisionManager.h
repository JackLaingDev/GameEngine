#ifndef TerrainCollisionManager_H 
#define TerrainCollisionManager_H

#include <iostream> 
#include <vector>

#include "EventManager.h"
#include "EntityManager.h"
#include "TerrainManager.h"
#include "Utils.h"

// Class declaration
class TerrainCollisionManager {
private:

	EventManager* eventManager;
	EntityManager* entityManager;
	TerrainManager* terrainManager;

public:

	TerrainCollisionManager(EventManager* eventManager, EntityManager* entityManager, TerrainManager* terrainManager);

	void terrainCollisionCheck();

};

#endif 
