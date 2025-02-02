#include "TerrainCollisionManager.h"

TerrainCollisionManager::TerrainCollisionManager(EventManager* eventManager, 
	EntityManager* entityManager, 
	TerrainManager* terrainManager) :
	eventManager(eventManager), 
	entityManager(entityManager), 
	terrainManager(terrainManager)
{
}

void TerrainCollisionManager::terrainCollisionCheck()
{
	auto collidableEntities = entityManager->getEntitiesByComponent<TerrainColliderComponent>();
	auto regions = terrainManager->regions;

	for (int i = 0; i < collidableEntities.size(); ++i) {
		for (int k = 0; k < regions.size(); ++k) {
			auto collider = entityManager->getComponent<TerrainColliderComponent>(collidableEntities[i]);
			auto region = regions[k];


			bool collisionDetected = Utils::isIn(*collider, region);
			if (collisionDetected) {
				std::cout << "Terrain Collision Detected\n"; // add event logic
			}
			else if (!collisionDetected) {
				std::cout << "No Terrain Collision Detected\n";
			}
			
		}
	}
}
