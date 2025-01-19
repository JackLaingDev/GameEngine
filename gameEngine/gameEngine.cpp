// gameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "GameLoop.h"

int main()
{
    // Initialise SFML
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML window");

    // Initialise systems
    std::unique_ptr entityManager = std::make_unique<EntityManager>();
    std::unique_ptr eventManager = std::make_unique<EventManager>();
    std::unique_ptr inputManager = std::make_unique<InputManager>(&window, eventManager.get());

    GameLoop game(std::move(entityManager), std::move(eventManager), std::move(inputManager));

    game.run();
}
