#include "GameLoop.h"

GameLoop::GameLoop(std::unique_ptr<EntityManager> entityManager,
	std::unique_ptr<EventManager> eventManager,
	std::unique_ptr<InputManager> inputManager,
	std::unique_ptr<RenderManager> renderManager,
	std::unique_ptr<MovementManager> movementManager,
	std::unique_ptr<CollisionManager> collisionManager,
	std::unique_ptr<EntityFactory> entityFactory)

	: entityManager(std::move(entityManager)),
	eventManager(std::move(eventManager)),
	inputManager(std::move(inputManager)),
	renderManager(std::move(renderManager)),
	movementManager(std::move(movementManager)),
	collisionManager(std::move(collisionManager)),
	entityFactory(std::move(entityFactory)),
	isRunning(false) {
}


void GameLoop::run()
{
	this->isRunning = true;

	// Initialise Entities
	entityFactory->playerEntity(1);
	entityFactory->testEntity(2);

	// Subscribe Events
	eventManager->subscribe(eventType::keyPress, [&](const Event& event) {
		movementManager->move(event);
		});

	// Game Loop
	while (isRunning) {

		// Game Loop logic goes here
		inputManager->update();
		collisionManager->collisionCheck();
		eventManager->publish();
		eventManager->events.clear();


		// Check for exit (ADD TO CUSTOM EVENTMANAGER)
		auto win = renderManager->getWindow();
		while (const std::optional eventSF = win->pollEvent()) {
			if (eventSF->is<sf::Event::Closed>()) {
				isRunning = false;
				win->close();
			}
			
		}

		renderManager->render();

	}
}
