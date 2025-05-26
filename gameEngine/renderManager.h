#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowHandle.hpp>

class EntityManager;
class TerrainManager;

class RenderManager {
private:
    std::unique_ptr<sf::RenderWindow> window;
    EntityManager* entityManager;
    TerrainManager* terrainManager;

public:
    RenderManager(sf::WindowHandle hwnd, EntityManager* entityManager, TerrainManager* terrainManager);
    sf::RenderWindow* getWindow();
    void renderEntities();
    void renderTerrain();
};