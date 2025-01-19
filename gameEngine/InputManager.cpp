#include "InputManager.h"

InputManager::InputManager(sf::Window* win, EventManager* em) : win(win), em(em)
{
}


void InputManager::update() {
    
    // Keys to check
    const std::vector<sf::Keyboard::Key> keysToCheck = {
    sf::Keyboard::Key::W,
    sf::Keyboard::Key::A,
    sf::Keyboard::Key::S,
    sf::Keyboard::Key::D,
    sf::Keyboard::Key::Space,
    sf::Keyboard::Key::Escape
    };

     // event type will always be keypress for input manager as its only looking for keypreses

    // Process events
    while (const std::optional eventSF = win->pollEvent())
    {
        // Check for Keypress
        if (eventSF->is<sf::Event::KeyPressed>()) {

            for (const auto& key : keysToCheck)
            {
                if (sf::Keyboard::isKeyPressed(key))
                {
                    // Create and publish custom event
                    Event event;
                    event.type = eventType::keyPress;
                    event.data = keyPressData{ key };

                    em->publish(event); // Publish the event to the EventManager
                }
            }
        }
    }
}

