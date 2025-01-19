#ifndef RenderManager_H 
#define RenderManager_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Class declaration
class RenderManager {
private:
    std::unique_ptr<sf::RenderWindow> window;

public:
    
    RenderManager(std::unique_ptr<sf::RenderWindow> window);

    void render();

};

#endif 
