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
    bool collided = false;

	if (collidableEntities.size() <= 1) {
		return;
	}
	for (int i = 0; i < collidableEntities.size(); ++i) {
		for (int k = i+1; k < collidableEntities.size(); ++k) {
			auto transform1 = entityManager->getComponent<TransformComponent>(collidableEntities[i]);
			auto transform2 = entityManager->getComponent<TransformComponent>(collidableEntities[k]);

            sf::FloatRect collider1Bounds(transform1->position, transform1->size);
            sf::FloatRect collider2Bounds(transform2->position, transform2->size);

            if (collider1Bounds.findIntersection(collider2Bounds)) {
                collided = true;

                // Get terrain and entity sides
                float collider1Left = collider1Bounds.position.x;
                float collider1Right = collider1Left + collider1Bounds.size.x;
                float collider1Top = collider1Bounds.position.y;
                float collider1Bottom = collider1Top + collider1Bounds.size.y;

                float collider2Left = collider2Bounds.position.x;
                float collider2Right = collider2Left + collider2Bounds.size.x;
                float collider2Top = collider2Bounds.position.y;
                float collider2Bottom = collider2Top + collider2Bounds.size.y;

                // Calculate their overlaps
                float overlapLeft = collider1Right - collider2Left;
                float overlapRight = collider2Right - collider1Left;
                float overlapTop = collider1Bottom - collider2Top;
                float overlapBottom = collider2Bottom - collider1Top;

                // Get collisions
                bool collisionFromLeft = (overlapLeft < overlapRight) && (overlapLeft < overlapTop) && (overlapLeft < overlapBottom);
                bool collisionFromRight = (overlapRight < overlapLeft) && (overlapRight < overlapTop) && (overlapRight < overlapBottom);
                bool collisionFromTop = (overlapTop < overlapBottom) && (overlapTop < overlapLeft) && (overlapTop < overlapRight);
                bool collisionFromBottom = (overlapBottom < overlapTop) && (overlapBottom < overlapLeft) && (overlapBottom < overlapRight);

                if (collisionFromLeft) {
                    std::cout << "Collision from left";
                }
                else if (collisionFromRight) {
                    std::cout << "Collision from right";
                }

                if (collisionFromTop) {
                    std::cout << "Collision from top";
                }
                else if (collisionFromBottom) {
                    std::cout << "Collision from bottom";
                }

            }
        }
        if (!collided) {
            // logic for no collisions if necessary
        }
	}
}

