#include "InputManager.h"

InputManager::InputManager(sf::RenderWindow* win_ptr, EventManager* eventManager, EntityManager* entityManager)
    : window(win_ptr), eventManager(eventManager), entityManager(entityManager), speed(200)
{
}

void InputManager::update() {
    Entity playerEntity(0);
    VelocityComponent* playerVelocity = nullptr;
    auto playerEntities = entityManager->getEntitiesByComponent<PlayerComponent>();
    if (!playerEntities.empty()) {
        playerEntity = playerEntities[0];
        playerVelocity = entityManager->getComponent<VelocityComponent>(playerEntity);
    }
    if (playerVelocity) {
        processHeldKeys(playerVelocity);
    }
}

// CORRECTED: Now receives sf::Event::KeyPressed
void InputManager::processKeyPresses(const sf::Event::KeyPressed& eventSF)
{
    auto key = eventSF.scancode;
    heldKeys.insert(key);
}

// CORRECTED: Now receives sf::Event::KeyReleased
void InputManager::processKeyReleases(const sf::Event::KeyReleased& eventSF)
{
    auto key = eventSF.scancode;
    heldKeys.erase(key);
}

void InputManager::processHeldKeys(VelocityComponent* playerVelocity)
{
    if (!playerVelocity) return;
    playerVelocity->velocity.x = 0.f;

    if (heldKeys.count(sf::Keyboard::Scancode::S)) {
        playerVelocity->velocity.y += speed;
    }
    if (heldKeys.count(sf::Keyboard::Scancode::A)) {
        playerVelocity->velocity.x -= speed;
    }
    if (heldKeys.count(sf::Keyboard::Scancode::D)) {
        playerVelocity->velocity.x += speed;
    }

    if (heldKeys.count(sf::Keyboard::Scancode::Escape)) {
        if (window) {
            window->close();
        }
    }
}