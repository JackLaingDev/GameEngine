#pragma once

#include <iostream>
#include <memory>
#include <SFML/Window/WindowHandle.hpp>

// Forward declare your manager classes
class EntityManager;
class EventManager;
class InputManager;
class RenderManager;
class MovementManager;
class CollisionManager;
class EntityFactory;
class TerrainManager;
class TerrainCollisionManager;
class PhysicsManager;

class GameEngine {
private:
    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<EventManager> eventManager;
    std::unique_ptr<InputManager> inputManager;
    std::unique_ptr<RenderManager> renderManager;
    std::unique_ptr<MovementManager> movementManager;
    std::unique_ptr<CollisionManager> collisionManager;
    std::unique_ptr<EntityFactory> entityFactory;
    std::unique_ptr<TerrainManager> terrainManager;
    std::unique_ptr<TerrainCollisionManager> terrainCollisionManager;
    std::unique_ptr<PhysicsManager> physicsManager;

    bool isRunning;

public:
    GameEngine();
    void initialise(sf::WindowHandle hwnd);
    void run();
    void stop();
};