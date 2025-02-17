#include "MovementManager.h"

MovementManager::MovementManager(EntityManager* entityManager) : entityManager(entityManager)
{
}


// Collider componenet should derive its position from the transofmr componenet within the collision system not here
void MovementManager::update(const Event& event)
{
	const auto& entitiesToMove = entityManager->getEntitiesByComponent<PlayerComponent>();

	for (const auto& entity : entitiesToMove) {
		auto velocityComponent = entityManager->getComponent<VelocityComponent>(entity);
		auto transformComponent = entityManager->getComponent<TransformComponent>(entity);
		auto colliderComponent = entityManager->getComponent<ColliderComponent>(entity);
		auto terrainColliderComponent = entityManager->getComponent<TerrainColliderComponent>(entity);

		if (event.type == eventType::keyPress) {

			auto eventData = std::get<keyPressData>(event.data);
			auto currentPos = transformComponent->position;

			switch (eventData.key)
			{
			case sf::Keyboard::Key::W:
				transformComponent->position = sf::Vector2f(currentPos.x, currentPos.y - velocityComponent->velocity.y);
				colliderComponent->position = transformComponent->position;
				terrainColliderComponent->position = transformComponent->position;
				break;
			case sf::Keyboard::Key::A:
				transformComponent->position = sf::Vector2f(currentPos.x - velocityComponent->velocity.x, currentPos.y);
				colliderComponent->position = transformComponent->position;
				terrainColliderComponent->position = transformComponent->position;
				break;
			case sf::Keyboard::Key::S:
				transformComponent->position = sf::Vector2f(currentPos.x, currentPos.y + velocityComponent->velocity.y);
				colliderComponent->position = transformComponent->position;
				terrainColliderComponent->position = transformComponent->position;
				break;
			case sf::Keyboard::Key::D:
				transformComponent->position = sf::Vector2f(currentPos.x + velocityComponent->velocity.x, currentPos.y);
				colliderComponent->position = transformComponent->position;
				terrainColliderComponent->position = transformComponent->position;
				break;
			}
		}
	}
}
