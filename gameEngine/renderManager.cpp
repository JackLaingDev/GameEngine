#include "RenderManager.h"
#include "EntityManager.h"
#include "TerrainManager.h"
#include <SFML/Graphics.hpp>

RenderManager::RenderManager(sf::WindowHandle hwnd, EntityManager* em, TerrainManager* tm)
    : entityManager(em), terrainManager(tm)
{
    window = std::make_unique<sf::RenderWindow>(hwnd);
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);
}

void RenderManager::renderEntities()
{
    if (!window || !entityManager) {
        std::cerr << "ERROR: RenderManager::renderEntities: Window or EntityManager not valid.\n";
        return;
    }

    const auto& entitiesToRender = entityManager->getEntitiesByComponent<RectangleComponent>();

    for (const auto& entity : entitiesToRender) {
        // Use getComponent and check for nullptr
        RectangleComponent* rectComponent = entityManager->getComponent<RectangleComponent>(entity);
        TransformComponent* transformComponent = entityManager->getComponent<TransformComponent>(entity);

        if (rectComponent && transformComponent) { // Only draw if both components are found
            rectComponent->rectangle.setPosition(transformComponent->position);
            window->draw(rectComponent->rectangle);
        }
    }
    // IMPORTANT: window->display() should be called ONCE per frame in GameEngine::run()
    // It should NOT be here.
}

void RenderManager::renderTerrain()
{
    if (!window || !terrainManager) {
        std::cerr << "ERROR: RenderManager::renderTerrain: Window or TerrainManager not valid.\n";
        return;
    }
    // window->clear(sf::Color::Black); // This should be done once per frame in GameEngine::run()
    auto regions = terrainManager->regions;
    for (const auto& region : regions) {
        window->draw(region.rect);
    }
}

sf::RenderWindow* RenderManager::getWindow()
{
    return window.get();
}