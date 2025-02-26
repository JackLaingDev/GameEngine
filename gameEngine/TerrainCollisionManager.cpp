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
    auto terrainCollidableEntities = entityManager->getEntitiesByComponent<TerrainColliderComponent>();
    auto regions = terrainManager->regions;

    for (auto entity : terrainCollidableEntities) {
        auto velocity = entityManager->getComponent<VelocityComponent>(entity);
        auto transform = entityManager->getComponent<TransformComponent>(entity);

        sf::FloatRect entityBounds(transform->position, transform->size);
        bool collided = false;                                                    // collided flag to reset velocity

        for (auto& region : regions) {
            sf::FloatRect terrainBounds(region.pos, region.size);
            
            if (entityBounds.findIntersection(terrainBounds)) {
                collided = true;

                // Get terrain and entity sides
                float entityLeft = entityBounds.position.x;
                float entityRight = entityLeft + entityBounds.size.x;
                float entityTop = entityBounds.position.y;
                float entityBottom = entityTop + entityBounds.size.y;

                float terrainLeft = terrainBounds.position.x;
                float terrainRight = terrainLeft + terrainBounds.size.x;
                float terrainTop = terrainBounds.position.y;
                float terrainBottom = terrainTop + terrainBounds.size.y;

                // Calculate their overlaps
                float overlapLeft = entityRight - terrainLeft;
                float overlapRight = terrainRight - entityLeft;
                float overlapTop = entityBottom - terrainTop;
                float overlapBottom = terrainBottom - entityTop;

                // Get collisions
                bool collisionFromLeft = (overlapLeft < overlapRight) && (overlapLeft < overlapTop) && (overlapLeft < overlapBottom);
                bool collisionFromRight = (overlapRight < overlapLeft) && (overlapRight < overlapTop) && (overlapRight < overlapBottom);
                bool collisionFromTop = (overlapTop < overlapBottom) && (overlapTop < overlapLeft) && (overlapTop < overlapRight);
                bool collisionFromBottom = (overlapBottom < overlapTop) && (overlapBottom < overlapLeft) && (overlapBottom < overlapRight);

                if (collisionFromLeft) {
                    transform->position.x = terrainLeft - entityBounds.size.x;
                    velocity->velocity.x = std::max(0.0f, velocity->velocity.x);  // Preserve intended movement
                }
                else if (collisionFromRight) {
                    transform->position.x = terrainRight;
                    velocity->velocity.x = std::min(0.0f, velocity->velocity.x);
                }

                if (collisionFromTop) {
                    transform->position.y = terrainTop - entityBounds.size.y;
                    velocity->velocity.y = std::max(0.0f, velocity->velocity.y);
                }
                else if (collisionFromBottom) {
                    transform->position.y = terrainBottom;
                    velocity->velocity.y = std::min(0.0f, velocity->velocity.y);
                }

            }
        }
        if (!collided) {
            velocity->velocity.x = 0.03f;
            velocity->velocity.y = 0.03f;
        }
    }
}
