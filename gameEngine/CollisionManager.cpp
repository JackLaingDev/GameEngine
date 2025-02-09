#include "CollisionManager.h"
#include "Utils.h"

CollisionManager::CollisionManager(EventManager* eventManager, EntityManager* entityManager) 
	: eventManager(eventManager), entityManager(entityManager)
{

}

void CollisionManager::collisionCheck()
{
	auto collidableEntities = entityManager->getEntitiesByComponent<ColliderComponent>();
	std::vector<Entity> collidedEntities;

	if (collidableEntities.size() <= 1) {
		return;
	}
	for (int i = 0; i < collidableEntities.size(); ++i) {
		for (int k = i+1; k < collidableEntities.size(); ++k) {
			auto collider1 = entityManager->getComponent<ColliderComponent>(collidableEntities[i]);
			auto collider2 = entityManager->getComponent<ColliderComponent>(collidableEntities[k]);

			if (collider1 != collider2) {
				continue;
			}
		}
	}
}

