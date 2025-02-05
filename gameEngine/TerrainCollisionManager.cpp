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
			auto velocity = entityManager->getComponent<VelocityComponent>(collidableEntities[i]);
			auto region = regions[k];

			auto inX = Utils::isIn(*collider, region)[0];
			auto inY = Utils::isIn(*collider, region)[1];

			if (inX) {
				velocity->velocity.x = 0; // add event logic
			}
			else if (!inX) {
				velocity->velocity.x = 0.2;
			}
			if (inY) {
				velocity->velocity.y = 0; // add event logic
			}
			else if (!inY) {
				velocity->velocity.y = 0.2;
			}
		}
	}
}
