// gameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "GameLoop.h"

int main()
{
    std::unique_ptr em = std::make_unique<EntityManager>();
    GameLoop game(std::move(em));

    game.run();
}
