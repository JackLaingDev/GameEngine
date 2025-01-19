// gameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "GameLoop.h"

int main()
{
    // Initialise SFML
    std::unique_ptr window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ 800, 600 }), "SFML window");

    // Initialise systems
    std::unique_ptr entityManager = std::make_unique<EntityManager>();
    std::unique_ptr eventManager = std::make_unique<EventManager>();
    std::unique_ptr inputManager = std::make_unique<InputManager>(window.get(), eventManager.get());
    std::unique_ptr renderManager = std::make_unique<RenderManager>(std::move(window), entityManager.get());

    GameLoop game(std::move(entityManager), std::move(eventManager), std::move(inputManager),
        std::move(renderManager));

    game.run();
}
