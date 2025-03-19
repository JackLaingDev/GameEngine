#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(EntityManager* entityManager) : entityManager(entityManager), gravity(sf::Vector2f(0, 90))
{

}

void PhysicsManager::update(float deltatime)
{
	auto physicsEntities = entityManager->getEntitiesByComponent<PhysicsComponent>();
	
	for (auto entity : physicsEntities) {
		auto velocityComponent = entityManager->getComponent<VelocityComponent>(entity);

		velocityComponent->velocity += gravity;
	}

}
