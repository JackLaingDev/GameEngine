#ifndef RenderManager_H 
#define RenderManager_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "EntityManager.h"
#include "TerrainManager.h"

// Class declaration
class RenderManager {
private:
    std::unique_ptr<sf::RenderWindow> window;
    EntityManager* entityManager;
    TerrainManager* terrainManager;

public:
    
    RenderManager(std::unique_ptr<sf::RenderWindow> window, EntityManager* entityManager, TerrainManager* terrainManager);

    void render();
    sf::RenderWindow* getWindow();

};

#endif 
