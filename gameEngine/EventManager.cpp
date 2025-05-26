#include "EventManager.h"

EventManager::EventManager(sf::RenderWindow* win_ptr) : window(win_ptr) {}

void EventManager::enqueue(const Event& customEvent) {
    customEvents.push_back(customEvent);
}

void EventManager::enqueue(const sf::Event& sfmlEvent) {
    sfmlEvents.push_back(sfmlEvent);
}

void EventManager::subscribe(eventType type, std::function<void(const Event&)> callback) {
    customSubscribers[type].push_back(callback);
}

void EventManager::publish() {
    // Publish custom events
    for (auto& event : customEvents) {
        if (customSubscribers.count(event.type)) {
            for (auto& callback : customSubscribers[event.type]) {
                callback(event);
            }
        }
    }

    // CORRECTED: Publish SFML events using getIf<T>() and dispatch to the correct subscriber lists
    for (const auto& event : sfmlEvents) {
        // Key events (KeyPressed, KeyReleased)
        if (event.getIf<sf::Event::KeyPressed>()) { // Check if it's a KeyPressed event specifically
            auto it = sfmlSubscribers.find(std::type_index(typeid(sf::Event::KeyPressed)));
            if (it != sfmlSubscribers.end()) {
                for (auto& callback : it->second) {
                    callback(event); // The lambda will handle getIf<sf::Event::KeyPressed>()
                }
            }
        }
        else if (event.getIf<sf::Event::KeyReleased>()) { // Check if it's a KeyReleased event specifically
            auto it = sfmlSubscribers.find(std::type_index(typeid(sf::Event::KeyReleased)));
            if (it != sfmlSubscribers.end()) {
                for (auto& callback : it->second) {
                    callback(event); // The lambda will handle getIf<sf::Event::KeyReleased>()
                }
            }
        }
        // Mouse Button events
        else if (event.getIf<sf::Event::MouseButtonPressed>()) {
            auto it = sfmlSubscribers.find(std::type_index(typeid(sf::Event::MouseButtonPressed)));
            if (it != sfmlSubscribers.end()) {
                for (auto& callback : it->second) {
                    callback(event);
                }
            }
        }
        else if (event.getIf<sf::Event::MouseButtonReleased>()) {
            auto it = sfmlSubscribers.find(std::type_index(typeid(sf::Event::MouseButtonReleased)));
            if (it != sfmlSubscribers.end()) {
                for (auto& callback : it->second) {
                    callback(event);
                }
            }
        }
        // Mouse Move event
        else if (event.getIf<sf::Event::MouseMoved>()) {
            auto it = sfmlSubscribers.find(std::type_index(typeid(sf::Event::MouseMoved)));
            if (it != sfmlSubscribers.end()) {
                for (auto& callback : it->second) {
                    callback(event);
                }
            }
        }
        // Add more 'else if' blocks for other specific sf::Event types you subscribe to:
        // sf::Event::Closed, sf::Event::Resized, sf::Event::TextEntered, etc.
        // For events without data (like Closed, FocusLost/Gained, MouseEntered/Left), you'd use event.is<T>()
        // and then find the subscriber list for that specific type.
        // Example for Closed event:
        // else if (event.is<sf::Event::Closed>()) {
        //     auto it = sfmlSubscribers.find(std::type_index(typeid(sf::Event::Closed)));
        //     if (it != sfmlSubscribers.end()) {
        //         for (auto& callback : it->second) {
        //             callback(event);
        //         }
        //     }
        // }
    }

    customEvents.clear();
    sfmlEvents.clear();
}