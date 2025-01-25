#include "MovementManager.h"

MovementManager::MovementManager(EntityManager* entityManager) : entityManager(entityManager)
{
}

void MovementManager::move(const Event& event)
{
	const auto& entitiesToMove = entityManager->getEntitiesByComponent<PlayerComponent>();

	for (const auto& entity : entitiesToMove) {
		auto velocityComponent = entityManager->getComponent<VelocityComponent>(entity);
		auto transformComponent = entityManager->getComponent<TransformComponent>(entity);

		if (event.type == eventType::keyPress) {

			auto eventData = std::get<keyPressData>(event.data);
			auto currentPos = transformComponent->position;

			switch (eventData.key)
			{
			case sf::Keyboard::Key::W:
				transformComponent->position = sf::Vector2f(currentPos.x, currentPos.y - velocityComponent->velocity.y);
				break;
			case sf::Keyboard::Key::A:
				transformComponent->position = sf::Vector2f(currentPos.x - velocityComponent->velocity.x, currentPos.y);
				break;
			case sf::Keyboard::Key::S:
				transformComponent->position = sf::Vector2f(currentPos.x, currentPos.y + velocityComponent->velocity.y);
				break;
			case sf::Keyboard::Key::D:
				transformComponent->position = sf::Vector2f(currentPos.x + velocityComponent->velocity.x, currentPos.y);
				break;
			}
		}
	}
}
