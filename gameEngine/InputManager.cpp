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

    while (const std::optional eventSF = win->pollEvent()) {
        processKeyEvents(eventSF);
    }

    processHeldKeys(playerVelocity);
}

void InputManager::processKeyEvents(const std::optional<sf::Event> eventSF)
{
    if (eventSF->is<sf::Event::KeyPressed>()) {
        const auto* keyPressed = eventSF->getIf<sf::Event::KeyPressed>();
        auto key = keyPressed->scancode;

        heldKeys.insert(key);
    }
    if (eventSF->is<sf::Event::KeyReleased>()) {
        const auto* keyReleased = eventSF->getIf<sf::Event::KeyReleased>();
        auto key = keyReleased->scancode;

        heldKeys.erase(key);
    }
}

void InputManager::processHeldKeys(VelocityComponent* playerVelocity)
{
    // W
    if (heldKeys.find(sf::Keyboard::Scancode::W) != heldKeys.end()) {
        playerVelocity->velocity.y -= speed;
    }
    else if (heldKeys.find(sf::Keyboard::Scancode::W) == heldKeys.end() && heldKeys.find(sf::Keyboard::Scancode::S) == heldKeys.end()) {
        playerVelocity->velocity.y = 0;
    }

    // A
    if (heldKeys.find(sf::Keyboard::Scancode::A) != heldKeys.end()) {
        playerVelocity->velocity.x -= speed;
    }
    else if (heldKeys.find(sf::Keyboard::Scancode::A) == heldKeys.end() && heldKeys.find(sf::Keyboard::Scancode::D) == heldKeys.end()) {
        playerVelocity->velocity.x = 0;
    }

    // S
    if (heldKeys.find(sf::Keyboard::Scancode::S) != heldKeys.end()) {
        playerVelocity->velocity.y += speed;
    }
    else if (heldKeys.find(sf::Keyboard::Scancode::W) == heldKeys.end() && heldKeys.find(sf::Keyboard::Scancode::S) == heldKeys.end()) {
        playerVelocity->velocity.y = 0;
    }

    // D
    if (heldKeys.find(sf::Keyboard::Scancode::D) != heldKeys.end()) {
        playerVelocity->velocity.x += speed;
    }
    else if (heldKeys.find(sf::Keyboard::Scancode::A) == heldKeys.end() && heldKeys.find(sf::Keyboard::Scancode::D) == heldKeys.end()) {
        playerVelocity->velocity.x = 0;
    }

    // Escape
    if (heldKeys.find(sf::Keyboard::Scancode::Escape) != heldKeys.end()) {
        win->close();
    }
}

