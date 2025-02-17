#ifndef InputManager_H 
#define InputManager_H

#include <iostream> 
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "EventManager.h"
#include "EntityManager.h"

// Class declaration
class InputManager {
private:
    sf::Window* win;
    EventManager* eventManager;
    EntityManager* entityManager;

    std::unordered_map<sf::Keyboard::Scancode, std::function<void()>> keyPresses;
    std::unordered_map<sf::Keyboard::Scancode, std::function<void()>> keyReleases;

public:
    InputManager(sf::Window* win, EventManager* eventManager, EntityManager* entityManager);
    void update();
};

#endif
