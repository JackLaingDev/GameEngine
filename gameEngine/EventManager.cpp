#include "EventManager.h"

/*
Subscribe functions to events in gameloop, when an event is published it will call the corresponding function.
*/
void EventManager::subscribe(eventType type, std::function<void(const Event&)> callback) {
    // Add the callback to the list of subscribers for the given event type
    customSubscribers[type].push_back(callback);
}

void EventManager::subscribe(sf::Event type, std::function<void(const sf::Event&)> callback)
{
    SFMLSubscribers[type].push_back(callback);
}

/*
Iterates through both custom and SFML event queues, calls their corresponding functions
*/
void EventManager::publish() {

    for (auto& event : customEvents) {
        // Check if there are subscribers for the event's type
        if (customSubscribers.find(event.type) != customSubscribers.end()) {
            // Invoke each callback with the event
            for (auto& callback : customSubscribers[event.type]) {
                callback(event);
            }
        }
    }
    for (auto& event : SFMLEvents) {
        // Check if there are subscribers for the event's type
        if (SFMLSubscribers.find(event) != SFMLSubscribers.end()) {
            // Invoke each callback with the event
            for (auto& callback : SFMLSubscribers[event]) {
                callback(event);
            }
        }
    }

}