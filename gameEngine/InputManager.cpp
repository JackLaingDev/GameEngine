#include "InputManager.h"

InputManager::InputManager(sf::Window* win, EventManager* eventManager, EntityManager* entityManager) 
    : win(win), eventManager(eventManager), entityManager(entityManager)
{
}


void InputManager::update() {

    // Process events

    auto player = entityManager->getEntitiesByComponent<PlayerComponent>()[0];
    auto playerVelocity = entityManager->getComponent<VelocityComponent>(player);

    keyPresses = {
    {sf::Keyboard::Scancode::W, [this, playerVelocity]() {playerVelocity->velocity.y -= this->speed; }},
    {sf::Keyboard::Scancode::A, [this, playerVelocity]() {playerVelocity->velocity.x -= this->speed; }},
    {sf::Keyboard::Scancode::S, [this, playerVelocity]() {playerVelocity->velocity.y += this->speed; }},
    {sf::Keyboard::Scancode::D, [this, playerVelocity]() {playerVelocity->velocity.x += this->speed; }}
    };

    keyReleases = {
    {sf::Keyboard::Scancode::W, [this, playerVelocity]() {playerVelocity->velocity.x = 0; }},
    {sf::Keyboard::Scancode::A, [this, playerVelocity]() {playerVelocity->velocity.x = 0; }},
    {sf::Keyboard::Scancode::S, [this, playerVelocity]() {playerVelocity->velocity.x = 0; }},
    {sf::Keyboard::Scancode::D, [this, playerVelocity]() {playerVelocity->velocity.x = 0; }}
    };

    while (const std::optional eventSF = win->pollEvent()) {
        if (eventSF->is<sf::Event::KeyPressed>()) {
            const auto* keyPressed = eventSF->getIf<sf::Event::KeyPressed>();
            auto key = keyPressed->scancode;

            auto it = keyPresses.find(key);
            if (it != keyPresses.end()) {
                it->second();  // Call the lambda function
            }
        }
        else if (eventSF->is<sf::Event::KeyReleased>()) {
            const auto* keyReleased = eventSF->getIf<sf::Event::KeyReleased>();
            auto key = keyReleased->scancode;

            auto it = keyReleases.find(key);
            if (it != keyReleases.end()) {
                it->second();  // Call the lambda function
            }
        }
        
    }
}

