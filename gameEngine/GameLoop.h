#ifndef GameLoop_H 
#define GameLoop_H

#include <iostream> 

#include "EntityManager.h"

class GameLoop {
private:

	std::unique_ptr<EntityManager> em;
	bool isRunning;

public:

	GameLoop(std::unique_ptr<EntityManager> em);

	void run();

};


#endif 
