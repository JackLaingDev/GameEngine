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
        processKeys(eventSF);
    }
}

void InputManager::processKeys(const std::optional<sf::Event> eventSF)
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

