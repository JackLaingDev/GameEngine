#ifndef InputManager_H 
#define InputManager_H

#include <iostream> 
#include <unordered_set>
#include <algorithm>
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

    std::unordered_set<sf::Keyboard::Scancode> heldKeys;

    Entity player = Entity(0);
    VelocityComponent* playerVelocity = new VelocityComponent(sf::Vector2f(0, 0));

    float speed = 200;

public:

    InputManager(sf::Window* win, EventManager* eventManager, EntityManager* entityManager);

    void update();
    void processKeyEvents(const std::optional<sf::Event> eventSF);
    void processHeldKeys(VelocityComponent* playerVelocity);
};

#endif
