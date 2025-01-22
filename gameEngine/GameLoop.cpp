#include "GameLoop.h"

GameLoop::GameLoop(std::unique_ptr<EntityManager> entityManager,
	std::unique_ptr<EventManager> eventManager,
	std::unique_ptr<InputManager> inputManager,
	std::unique_ptr<RenderManager> renderManager,
	std::unique_ptr<MovementManager> movementManager)
	: entityManager(std::move(entityManager)),
	eventManager(std::move(eventManager)),
	inputManager(std::move(inputManager)),
	renderManager(std::move(renderManager)),
	movementManager(std::move(movementManager)),
	isRunning(false) {
}


void GameLoop::run()
{
	this->isRunning = true;

	Entity testEntity(1);
	sf::RectangleShape rect;

	// Initialise Entities
	entityManager->addComponent<TransformComponent>(testEntity, sf::Vector2f(100, 100));
	entityManager->addComponent<RectangleComponent>(testEntity, rect, sf::Vector2f(100, 100), sf::Color::Red);
	entityManager->addComponent<PlayerComponent>(testEntity, 1);
	entityManager->addComponent<VelocityComponent>(testEntity, 0.3);

	// Subscribe Events
	eventManager->subscribe(eventType::keyPress, [&](const Event& event) {
		movementManager->move(event);
		});

	// Game Loop
	while (isRunning) {

		// Game Loop logic goes here
		// take input
		// update systems
		// process events
		// render

		inputManager->update();
		eventManager->publish();
		eventManager->events.clear();
		// Check for exit
		auto win = renderManager->getWindow();
		while (const std::optional eventSF = win->pollEvent()) {
			if (eventSF->is<sf::Event::Closed>()) {
				isRunning = false;
			}
			
		}

		renderManager->render();

	}
}
