#include "InputManager.h"

InputManager::InputManager(sf::Window* win, EventManager* eventManager, EntityManager* entityManager) 
    : win(win), eventManager(eventManager), entityManager(entityManager)
{

}

void InputManager::update() {

    // Process events
    auto entities = entityManager->getEntitiesByComponent<PlayerComponent>();

    if (entities.size() != 0) {
        player = entities[0];
        playerVelocity = entityManager->getComponent<VelocityComponent>(player);
    }

    processHeldKeys(playerVelocity);
}

void InputManager::processKeyPresses(const sf::Event::KeyPressed& eventSF)
{
    auto key = eventSF.scancode;

    heldKeys.insert(key);
    update();
}

void InputManager::processKeyReleases(const sf::Event::KeyReleased& eventSF)
{
    auto key = eventSF.scancode;

    heldKeys.erase(key);
    update();
}

void InputManager::processHeldKeys(VelocityComponent* playerVelocity)
{

    playerVelocity->velocity.x = 0.f;

    // Vertical Movement
    // W NEEDS TO BE ADDED AS A JUMP.
    if (heldKeys.find(sf::Keyboard::Scancode::S) != heldKeys.end()) {
        playerVelocity->velocity.y += speed;
    }

    // Horizontal Movement
    if (heldKeys.find(sf::Keyboard::Scancode::A) != heldKeys.end()) {
        playerVelocity->velocity.x -= speed;
    }
    if (heldKeys.find(sf::Keyboard::Scancode::D) != heldKeys.end()) {
        playerVelocity->velocity.x += speed;
    }

    // Escape handling
    if (heldKeys.find(sf::Keyboard::Scancode::Escape) != heldKeys.end()) {
        win->close();
    }

}

