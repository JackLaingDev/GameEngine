#include "InputManager.h"

InputManager::InputManager(sf::Window* win, EventManager* eventManager, EntityManager* entityManager) 
    : win(win), eventManager(eventManager), entityManager(entityManager)
{
}


void InputManager::update() {

    // Process events
    std::optional<sf::Event> eventSF;

    keyPresses = {
    {sf::Keyboard::Scancode::W, []() {std::cout << "W"; }},
    {sf::Keyboard::Scancode::A, []() {std::cout << "A"; }},
    {sf::Keyboard::Scancode::S, []() {std::cout << "S"; }},
    {sf::Keyboard::Scancode::D, []() {std::cout << "D"; }}
    };

    keyReleases = {
    {sf::Keyboard::Scancode::W, []() {std::cout << "Released W"; }},
    {sf::Keyboard::Scancode::A, []() {std::cout << "Released A"; }},
    {sf::Keyboard::Scancode::S, []() {std::cout << "Released S"; }},
    {sf::Keyboard::Scancode::D, []() {std::cout << "Released D"; }}
    };

    while ((eventSF = win->pollEvent())) {
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

