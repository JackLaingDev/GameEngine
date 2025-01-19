#include "GameLoop.h"

GameLoop::GameLoop(std::unique_ptr<EntityManager> entityManager,
	std::unique_ptr<EventManager> eventManager,
	std::unique_ptr<InputManager> inputManager)
	: entityManager(std::move(entityManager)),
	eventManager(std::move(eventManager)),
	inputManager(std::move(inputManager)),
	isRunning(false) {
}


void GameLoop::run()
{
	this->isRunning = true;

	// Initialise Entities


	// Game Loop
	while (isRunning) {

		// Game Loop logic goes here
		// take input
		// update systems
		// process events
		// render

	}
}
