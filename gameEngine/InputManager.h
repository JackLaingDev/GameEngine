#ifndef InputManager_H 
#define InputManager_H

#include <iostream> 
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "EventManager.h"

// Class declaration
class InputManager {
private:
    sf::Window* win;
    EventManager* em;

public:
    InputManager(sf::Window* win, EventManager* em);
    void update();
};

#endif
