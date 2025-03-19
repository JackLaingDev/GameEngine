#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(EntityManager* entityManager) : entityManager(entityManager)
{

}

void PhysicsManager::update(float deltatime)
{
	auto entities = entityManager->getEntitiesByComponent<PlayerComponent>();
	auto player = entities[0];

	auto velocityComponent = entityManager->getComponent<VelocityComponent>(player);
	auto transformComponent = entityManager->getComponent<TransformComponent>(player);
}
