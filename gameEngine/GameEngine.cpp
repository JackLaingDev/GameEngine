#include "GameEngine.h"

GameEngine::GameEngine()
    : isRunning(false) {
    // Systems not yet created—this happens in initialise()
}

void GameEngine::initialise(std::unique_ptr<sf::RenderWindow> win) {
    // Initialise window
    window = std::move(win);

    // Initialise systems
    entityManager = std::make_unique<EntityManager>();
    eventManager = std::make_unique<EventManager>(window.get());
    inputManager = std::make_unique<InputManager>(window.get(), eventManager.get(), entityManager.get());
    terrainManager = std::make_unique<TerrainManager>();
    renderManager = std::make_unique<RenderManager>(std::move(window), entityManager.get(), terrainManager.get());
    movementManager = std::make_unique<MovementManager>(entityManager.get());
    collisionManager = std::make_unique<CollisionManager>(eventManager.get(), entityManager.get());
    terrainCollisionManager = std::make_unique<TerrainCollisionManager>(eventManager.get(), entityManager.get(), terrainManager.get());
    physicsManager = std::make_unique<PhysicsManager>(entityManager.get());
    entityFactory = std::make_unique<EntityFactory>(entityManager.get());

    // Initial setup (entities, terrain, events) moved here
    entityFactory->playerEntity(1);
    entityFactory->testEntity(2);

    terrainManager->addRegion(sf::Vector2f(0, 600), sf::Vector2f(1700, 100), sf::Color::Blue);
    terrainManager->addRegion(sf::Vector2f(0, 300), sf::Vector2f(300, 50), sf::Color::Blue);
    terrainManager->addRegion(sf::Vector2f(1300, 300), sf::Vector2f(300, 50), sf::Color::Blue);

    eventManager->subscribe<sf::Event::KeyPressed>([this](const sf::Event::KeyPressed& event) {
        inputManager->processKeyPresses(event);
        });

    eventManager->subscribe<sf::Event::KeyReleased>([this](const sf::Event::KeyReleased& event) {
        inputManager->processKeyReleases(event);
        });

    eventManager->subscribe(eventType::collisionDetected, [](const Event& event) {
        std::cout << "Custom collision event triggered\n";
        });
}

void GameEngine::run() {
    this->isRunning = true;
    auto win = renderManager->getWindow();
    sf::Clock clock;

    while (isRunning) {
        float deltaTime = clock.restart().asSeconds();

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
