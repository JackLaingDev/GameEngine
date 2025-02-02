#ifndef GameLoop_H 
#define GameLoop_H

#include <iostream> 

#include "EntityManager.h"
#include "EventManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "MovementManager.h"
#include "EntityFactory.h"
#include "CollisionManager.h"
#include "TerrainManager.h"
#include "TerrainCollisionManager.h"

class GameLoop {
private:

	// Systems
	std::unique_ptr<EntityManager> entityManager;
	std::unique_ptr<EventManager> eventManager;
	std::unique_ptr<InputManager> inputManager;
	std::unique_ptr<RenderManager> renderManager;
	std::unique_ptr<MovementManager> movementManager;
	std::unique_ptr<CollisionManager> collisionManager;
	std::unique_ptr<EntityFactory> entityFactory;
	std::unique_ptr<TerrainManager> terrainManager;
	std::unique_ptr<TerrainCollisionManager> terrainCollisionManager;

	bool isRunning;

public:

	GameLoop(std::unique_ptr<EntityManager> entityManager, std::unique_ptr<EventManager> eventManager,
		std::unique_ptr<InputManager> inputManager, std::unique_ptr<RenderManager> renderManager,
		std::unique_ptr<MovementManager> movementManager, std::unique_ptr<CollisionManager> collisionManager,
		std::unique_ptr<TerrainManager> terrainManager, std::unique_ptr<EntityFactory> entityFactory,
		std::unique_ptr<TerrainCollisionManager> terrainCollisionManager);

	void run();

};


#endif 
