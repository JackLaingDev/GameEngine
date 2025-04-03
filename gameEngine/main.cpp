// gameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "GameEngine.h"

int main()
{
    GameEngine game;

    std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ 1700, 900 }), "SFML window");

    game.initialise(std::move(window));
    game.run();
}
