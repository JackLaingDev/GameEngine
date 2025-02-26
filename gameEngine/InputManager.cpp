#include "InputManager.h"

InputManager::InputManager(sf::Window* win, EventManager* eventManager, EntityManager* entityManager) 
    : win(win), eventManager(eventManager), entityManager(entityManager)
{
    keyPresses = {
    {sf::Keyboard::Scancode::W, [this]() {this->playerVelocity->velocity.y -= this->speed; std::cout << "w"; }},
    {sf::Keyboard::Scancode::A, [this]() {this->playerVelocity->velocity.x -= this->speed; }},
    {sf::Keyboard::Scancode::S, [this]() {this->playerVelocity->velocity.y += this->speed; }},
    {sf::Keyboard::Scancode::D, [this]() {this->playerVelocity->velocity.x += this->speed; }},
    {sf::Keyboard::Scancode::Escape, [this]() {this->win->close(); }}
    };

    keyReleases = {
    {sf::Keyboard::Scancode::W, [this]() {playerVelocity->velocity.y = 0; }},
    {sf::Keyboard::Scancode::A, [this]() {playerVelocity->velocity.x = 0; }},
    {sf::Keyboard::Scancode::S, [this]() {playerVelocity->velocity.y = 0; }},
    {sf::Keyboard::Scancode::D, [this]() {playerVelocity->velocity.x = 0; }}
    };
}


void InputManager::update() {

    // Process events
    auto entities = entityManager->getEntitiesByComponent<PlayerComponent>();

    if (entities.size() != 0) {
        player = entities[0];
        playerVelocity = entityManager->getComponent<VelocityComponent>(player);
    }

    while (const std::optional eventSF = win->pollEvent()) {
        if (eventSF->is<sf::Event::KeyPressed>()) {
            const auto* keyPressed = eventSF->getIf<sf::Event::KeyPressed>();
            auto key = keyPressed->scancode;

            auto it = keyPresses.find(key);
            if (it != keyPresses.end()) {
                it->second();  // Call the lambda function
            }
        }
        if (eventSF->is<sf::Event::KeyReleased>()) {
            const auto* keyReleased = eventSF->getIf<sf::Event::KeyReleased>();
            auto key = keyReleased->scancode;

            auto it = keyReleases.find(key);
            if (it != keyReleases.end()) {
                it->second();  // Call the lambda function
            }
        }
    }
}

