#include "CollisionManager.h"

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
		for (int k = 0; k < collidableEntities.size(); ++k) {
			auto collider1 = entityManager->getComponent<ColliderComponent>(collidableEntities[i]);
			auto collider2 = entityManager->getComponent<ColliderComponent>(collidableEntities[k]);

			if (collider1 != collider2) {
				bool collisionDetected = isIn(*collider1, *collider2);
				if (collisionDetected) {
					std::cout << "Collision Detected\n"; // add event logic
				}
				else if (!collisionDetected){
					std::cout << "No Collision Detected\n";
				}
			}
		}
	}
}

bool CollisionManager::isIn(ColliderComponent& collider1, ColliderComponent& collider2)
{
	auto collider1Pos = collider1.position;
	auto collider2Pos = collider2.position;

	auto collider1Size = collider1.size;
	auto collider2Size = collider2.size;
	
	bool inX = collider1Pos.x >= collider2Pos.x && collider1Pos.x <= collider2Pos.x + collider2Size.x;
	bool inY = collider1Pos.y >= collider2Pos.y && collider1Pos.y <= collider2Pos.y + collider2Size.y;

	if (inX && inY) {
		return true;
	}
	else {
		return false;
	}
}
