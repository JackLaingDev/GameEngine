#include "GameLoop.h"

GameLoop::GameLoop(std::unique_ptr<EntityManager> entityManager,
	std::unique_ptr<EventManager> eventManager,
	std::unique_ptr<InputManager> inputManager,
	std::unique_ptr<RenderManager> renderManager,
	std::unique_ptr<MovementManager> movementManager,
	std::unique_ptr<CollisionManager> collisionManager,
	std::unique_ptr<TerrainManager> terrainManager,
	std::unique_ptr<EntityFactory> entityFactory,
	std::unique_ptr<TerrainCollisionManager> terrainCollisionManager,
	std::unique_ptr<PhysicsManager> physicsManager)

	: entityManager(std::move(entityManager)),
	eventManager(std::move(eventManager)),
	inputManager(std::move(inputManager)),
	renderManager(std::move(renderManager)),
	movementManager(std::move(movementManager)),
	collisionManager(std::move(collisionManager)),
	terrainManager(std::move(terrainManager)),
	entityFactory(std::move(entityFactory)),
	terrainCollisionManager(std::move(terrainCollisionManager)),
	physicsManager(std::move(physicsManager)),
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
	terrainManager->addRegion(sf::Vector2f(0, 600), sf::Vector2f(1700, 100), sf::Color::Blue);
	terrainManager->addRegion(sf::Vector2f(0, 300), sf::Vector2f(300, 50), sf::Color::Blue);
	terrainManager->addRegion(sf::Vector2f(1300, 300), sf::Vector2f(300, 50), sf::Color::Blue);

	// Subscribe Events
	eventManager->subscribe<sf::Event::KeyPressed>([this](const sf::Event::KeyPressed& event) {
		inputManager->processKeyPresses(event);
		});

	eventManager->subscribe<sf::Event::KeyReleased>([this](const sf::Event::KeyReleased& event) {
		inputManager->processKeyReleases(event);
		});

	eventManager->subscribe(eventType::collisionDetected, [](const Event& event) {
		std::cout << "custom event queue test";
		});

	// Game Loop
	while (isRunning) {

		float deltaTime = clock.restart().asSeconds();

		// Game Loop logic goes here
		eventManager->pollSFMLEvents();
		physicsManager->update(deltaTime);
		movementManager->update(deltaTime);
		collisionManager->collisionCheck();
		terrainCollisionManager->terrainCollisionCheck();
		eventManager->publish();
		renderManager->renderTerrain();
		renderManager->renderEntities();



	}
}
