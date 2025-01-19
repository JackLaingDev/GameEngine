#include "GameLoop.h"

GameLoop::GameLoop(std::unique_ptr<EntityManager> em) : em(std::move(em)), isRunning(false) {}


void GameLoop::run()
{
	this->isRunning = true;

	while (isRunning) {

		// Game Loop logic goes here

	}
}
