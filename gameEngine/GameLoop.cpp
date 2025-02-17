#include "GameLoop.h"

GameLoop::GameLoop(std::unique_ptr<EntityManager> entityManager,
	std::unique_ptr<EventManager> eventManager,
	std::unique_ptr<InputManager> inputManager,
	std::unique_ptr<RenderManager> renderManager,
	std::unique_ptr<MovementManager> movementManager,
	std::unique_ptr<CollisionManager> collisionManager,
	std::unique_ptr<TerrainManager> terrainManager,
	std::unique_ptr<EntityFactory> entityFactory,
	std::unique_ptr<TerrainCollisionManager> terrainCollisionManager)

	: entityManager(std::move(entityManager)),
	eventManager(std::move(eventManager)),
	inputManager(std::move(inputManager)),
	renderManager(std::move(renderManager)),
	movementManager(std::move(movementManager)),
	collisionManager(std::move(collisionManager)),
	terrainManager(std::move(terrainManager)),
	entityFactory(std::move(entityFactory)),
	terrainCollisionManager(std::move(terrainCollisionManager)),
	isRunning(false) {
}


void GameLoop::run()
{
	this->isRunning = true;
	auto win = renderManager->getWindow();

	sf::Clock clock;

	// Initialise Entities
	entityFactory->playerEntity(1);
	entityFactory->testEntity(2);

	// Add Terrain
	//terrainManager->addRegion(sf::Vector2f(700, 500), sf::Vector2f(100, 100), sf::Color::Blue);

	// Subscribe Events

	// Game Loop
	while (isRunning) {

		float deltaTime = clock.restart().asSeconds();

		// Game Loop logic goes here
		inputManager->update();
		movementManager->update(deltaTime);
		//collisionManager->collisionCheck();
		//terrainCollisionManager->terrainCollisionCheck();
		//eventManager->publish();
		//eventManager->events.clear();
		renderManager->renderTerrain();
		renderManager->renderEntities();


		// Check for exit
		if (const std::optional eventSF = win->pollEvent()) {
			if (eventSF->is<sf::Event::Closed>()) {
				isRunning = false;
				win->close();
			}
		}
	}
}
