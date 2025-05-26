#ifndef InputManager_H
#define InputManager_H

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <SFML/Graphics.hpp> // For sf::RenderWindow and SFML event types like sf::Event::KeyPressed
#include "EventManager.h"
#include "EntityManager.h"
#include "Entity.h"            // Assuming you use this

class InputManager {
private:
    sf::RenderWindow* window;
    EventManager* eventManager;
    EntityManager* entityManager;
    std::unordered_set<sf::Keyboard::Scancode> heldKeys;
    float speed = 200;

public:
    InputManager(sf::RenderWindow* win_ptr, EventManager* eventManager, EntityManager* entityManager);
    void update();

    void processKeyPresses(const sf::Event::KeyPressed& eventSF);
    void processKeyReleases(const sf::Event::KeyReleased& eventSF);
    void processHeldKeys(VelocityComponent* playerVelocity);
};

#endif