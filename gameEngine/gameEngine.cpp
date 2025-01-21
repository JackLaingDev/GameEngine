// gameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "GameLoop.h"

int main()
{
    // Initialise SFML
    std::unique_ptr window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ 800, 600 }), "SFML window");

    // Initialise systems
    std::unique_ptr<EntityManager> entityManager = std::make_unique<EntityManager>();
    std::unique_ptr<EventManager> eventManager = std::make_unique<EventManager>();
    std::unique_ptr<InputManager> inputManager = std::make_unique<InputManager>(window.get(), eventManager.get());
    std::unique_ptr<RenderManager> renderManager = std::make_unique<RenderManager>(std::move(window), entityManager.get());
    std::unique_ptr<MovementManager> movementManager = std::make_unique<MovementManager>(entityManager.get());

    GameLoop game(std::move(entityManager), std::move(eventManager), std::move(inputManager),
        std::move(renderManager), std::move(movementManager));

    game.run();
}
