#include "MovementManager.h"

MovementManager::MovementManager(EntityManager* entityManager) : entityManager(entityManager)
{
}


// Collider componenet should derive its position from the transofmr componenet within the collision system not here
void MovementManager::update(float deltatime)
{
	auto entities = entityManager->getEntitiesByComponent<PlayerComponent>();
	auto player = entities[0];

	auto velocityComponent = entityManager->getComponent<VelocityComponent>(player);
	auto transformComponent = entityManager->getComponent<TransformComponent>(player);

	// Check for exceeding max velocities
	if (velocityComponent->velocity.x > velocityComponent->maxVelocity.x) {
		velocityComponent->velocity.x = velocityComponent->maxVelocity.x;
	}
	else if (velocityComponent->velocity.x < velocityComponent->minVelocity.x) {
		velocityComponent->velocity.x = velocityComponent->minVelocity.x;
	}

	// Check for exceeding min velocities
	if (velocityComponent->velocity.y > velocityComponent->maxVelocity.y) {
		velocityComponent->velocity.y = velocityComponent->maxVelocity.y;
	}
	else if (velocityComponent->velocity.y < velocityComponent->minVelocity.y) {
		velocityComponent->velocity.y = velocityComponent->minVelocity.y;
	}

	transformComponent->position.x += deltatime * velocityComponent->velocity.x;
	transformComponent->position.y += deltatime * velocityComponent->velocity.y;
	
}
