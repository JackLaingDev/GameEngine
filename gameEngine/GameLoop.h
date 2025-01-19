#ifndef GameLoop_H 
#define GameLoop_H

#include <iostream> 

#include "EntityManager.h"
#include "EventManager.h"
#include "InputManager.h"

class GameLoop {
private:

	std::unique_ptr<EntityManager> entityManager;
	std::unique_ptr<EventManager> eventManager;
	std::unique_ptr<InputManager> inputManager;
	bool isRunning;

public:

	GameLoop(std::unique_ptr<EntityManager> entityManager, std::unique_ptr<EventManager> eventManager,
		std::unique_ptr<InputManager> inputManager);

	void run();

};


#endif 
