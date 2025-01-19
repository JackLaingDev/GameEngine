#include "GameLoop.h"

GameLoop::GameLoop(std::unique_ptr<EntityManager> em) : em(std::move(em)), isRunning(false) {}


void GameLoop::run()
{
	this->isRunning = true;

	Entity entity(1);
	em->addComponent<HealthComponent>(entity, 100);

	while (isRunning) {

		// Game Loop logic goes here
		// take input
		// update systems
		// process events
		// render

	}
}
