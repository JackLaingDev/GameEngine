#include "InputManager.h"

InputManager::InputManager(sf::Window* win, EventManager* em) : win(win), em(em)
{
}


void InputManager::update() {
    
    std::optional<sf::Event> eventSF; // SFML Event

     // event type will always be keypress for input manager as its only looking for keypreses

    // Process events
    while (const std::optional eventSF = win->pollEvent())
    {
        // Check for Keypress
        if (eventSF->is<sf::Event::KeyPressed>()) {

            // Create game engine Event for W press
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                
                // Create Custom event
                Event event; 
                keyPressData kpData = { sf::Keyboard::Key::W };

                // Set event attributes
                event.type = eventType::keyPress;
                event.data = {kpData};
            }

            // Create game engine Event for A press
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

                // Create Custom event
                Event event;
                keyPressData kpData = { sf::Keyboard::Key::A };

                // Set event attributes
                event.type = eventType::keyPress;
                event.data = { kpData };
            }

            // Create game engine Event for S press
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {

                // Create Custom event
                Event event;
                keyPressData kpData = { sf::Keyboard::Key::S };

                // Set event attributes
                event.type = eventType::keyPress;
                event.data = { kpData };
            }

            // Create game engine Event for D press
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

                // Create Custom event
                Event event;
                keyPressData kpData = { sf::Keyboard::Key::D };

                // Set event attributes
                event.type = eventType::keyPress;
                event.data = { kpData };
            }

            // Create game engine Event for Space press
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {

                // Create Custom event
                Event event;
                keyPressData kpData = { sf::Keyboard::Key::Space };

                // Set event attributes
                event.type = eventType::keyPress;
                event.data = { kpData };
            }
        }
    }
}

