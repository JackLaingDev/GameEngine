#include "GameEngine.h"
#include "EntityManager.h"
#include "EventManager.h"
#include "InputManager.h"
#include "TerrainManager.h"
#include "RenderManager.h"
#include "MovementManager.h"
#include "CollisionManager.h"
#include "TerrainCollisionManager.h"
#include "PhysicsManager.h"
#include "EntityFactory.h"

#include <iostream>
#include <SFML/Graphics.hpp> // Includes sf::Event, sf::Color, sf::Clock etc.
#include <optional>          // For std::optional

GameEngine::GameEngine() : isRunning(false) {}

void GameEngine::initialise(sf::WindowHandle hwnd) {
    entityManager = std::make_unique<EntityManager>();
    terrainManager = std::make_unique<TerrainManager>();

    renderManager = std::make_unique<RenderManager>(hwnd, entityManager.get(), terrainManager.get());

    sf::RenderWindow* sfmlWindowPtr = renderManager->getWindow();

    if (sfmlWindowPtr) {
        eventManager = std::make_unique<EventManager>(sfmlWindowPtr);
        inputManager = std::make_unique<InputManager>(sfmlWindowPtr, eventManager.get(), entityManager.get());
    }
    else {
        std::cerr << "ERROR: RenderManager or its SFML window not initialized correctly in GameEngine::initialise.\n";
        return;
    }

    entityFactory = std::make_unique<EntityFactory>(entityManager.get());
    entityFactory->playerEntity(1);
    entityFactory->testEntity(2);

    terrainManager->addRegion(sf::Vector2f(0, 600), sf::Vector2f(1700, 100), sf::Color::Blue);
    terrainManager->addRegion(sf::Vector2f(0, 300), sf::Vector2f(300, 50), sf::Color::Blue);
    terrainManager->addRegion(sf::Vector2f(1300, 300), sf::Vector2f(300, 50), sf::Color::Blue);

    eventManager->subscribe<sf::Event::KeyPressed>([this](const sf::Event::KeyPressed& keyPressEvent) {

        inputManager->processKeyPresses(keyPressEvent); // Pass the specific keyPressEvent
        });

    eventManager->subscribe<sf::Event::KeyReleased>([this](const sf::Event::KeyReleased& keyReleaseEvent) {
        // No need to check keyReleaseEvent.type here
        inputManager->processKeyReleases(keyReleaseEvent); // Pass the specific keyReleaseEvent
        });

    eventManager->subscribe(eventType::collisionDetected, [](const Event& event) {
        std::cout << "Custom collision event triggered\n";
        });
}

void GameEngine::run() {
    this->isRunning = true;
    sf::Clock clock;

    if (!renderManager || !renderManager->getWindow() || !renderManager->getWindow()->isOpen()) {
        std::cerr << "ERROR: SFML RenderWindow not initialized or not open. Cannot start game loop.\n";
        isRunning = false;
        return;
    }

    while (isRunning && renderManager->getWindow()->isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        // CORRECTED: Poll SFML events using the SFML 3.0 signature: pollEvent() returns std::optional<sf::Event>
        while (std::optional<sf::Event> eventOpt = renderManager->getWindow()->pollEvent()) {
            if (eventOpt.has_value()) { // Check if an event was actually returned
                eventManager->enqueue(*eventOpt); // Enqueue the actual sf::Event object
            }
        }

        inputManager->update();

        physicsManager->update(deltaTime);
        movementManager->update(deltaTime);
        collisionManager->collisionCheck();
        terrainCollisionManager->terrainCollisionCheck();
        eventManager->publish(); // Publish both custom and SFML events

        renderManager->getWindow()->clear(sf::Color::Black);

        renderManager->renderTerrain();
        renderManager->renderEntities();

        renderManager->getWindow()->display();
    }

    if (renderManager && renderManager->getWindow() && renderManager->getWindow()->isOpen()) {
        renderManager->getWindow()->close();
        std::cout << "GameEngine run loop finished. SFML Window closed.\n";
    }
}

void GameEngine::stop() {
    isRunning = false;
    std::cout << "GameEngine stop() called. Signaling loop termination.\n";
}