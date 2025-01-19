// gameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "GameLoop.h"

int main()
{
    std::unique_ptr entityManager = std::make_unique<EntityManager>();
    std::unique_ptr eventManager = std::make_unique<EventManager>();
    GameLoop game(std::move(entityManager), std::move(eventManager));

    game.run();
}
