#ifndef GameLoop_H 
#define GameLoop_H

#include <iostream> 

#include "EntityManager.h"
#include "EventManager.h"

class GameLoop {
private:

	std::unique_ptr<EntityManager> entityManager;
	std::unique_ptr<EventManager> eventManager;
	bool isRunning;

public:

	GameLoop(std::unique_ptr<EntityManager> entityManager, std::unique_ptr<EventManager> eventManager);

	void run();

};


#endif 
