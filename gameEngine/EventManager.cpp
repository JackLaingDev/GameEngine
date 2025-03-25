#include "EventManager.h"

EventManager::EventManager(sf::Window* win) : win(win)
{
}

void EventManager::enqueue(const Event& customEvent)
{
    customEvents.push_back(customEvent);
}

void EventManager::enqueue(const sf::Event& sfmlEvent)
{
    SFMLEvents.push_back(sfmlEvent);
}

void EventManager::pollSFMLEvents()
{
    while (const std::optional eventSF = win->pollEvent()) {
        SFMLEvents.push_back(eventSF);
    }
}

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