#include "EventManager.h"

// std::function<void(const Event&)> can accept and store any function returning void with params: const Event& 
void EventManager::subscribe(eventType type, std::function<void(const Event&)> callback) {
    // Add the callback to the list of subscribers for the given event type
    subscribers[type].push_back(callback);
}

void EventManager::publish(const Event& event) {
    // Check if there are subscribers for the event's type
    if (subscribers.find(event.type) != subscribers.end()) {
        // Invoke each callback with the event
        for (auto& callback : subscribers[event.type]) {
            callback(event);
        }
    }
}