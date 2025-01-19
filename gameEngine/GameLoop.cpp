#include "GameLoop.h"

GameLoop::GameLoop(std::unique_ptr<EntityManager> em) : em(std::move(em)), isRunning(false) {}


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
