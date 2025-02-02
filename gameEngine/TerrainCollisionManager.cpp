#include "TerrainCollisionManager.h"

TerrainCollisionManager::TerrainCollisionManager(EventManager* eventManager, 
	EntityManager* entityManager, 
	TerrainManager* terrainManager) :
	eventManager(eventManager), 
	entityManager(entityManager), 
	terrainManager(terrainManager)
{
}
