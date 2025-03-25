#include "EventManager.h"

EventManager::EventManager(sf::Window* win) : win(win) {}

void EventManager::enqueue(const Event& customEvent) {
    customEvents.push_back(customEvent);
}

void EventManager::enqueue(const sf::Event& sfmlEvent) {
    sfmlEvents.push_back(sfmlEvent);
}

void EventManager::pollSFMLEvents() {
    while (const std::optional eventSF = win->pollEvent()) {
        enqueue(*eventSF);
    }
}

void EventManager::subscribe(eventType type, std::function<void(const Event&)> callback) {
    customSubscribers[type].push_back(callback);
}

void EventManager::publish() {
    for (auto& event : customEvents) {
        if (customSubscribers.find(event.type) != customSubscribers.end()) {
            for (auto& callback : customSubscribers[event.type]) {
                callback(event);
            }
        }
    }

    for (const auto& event : sfmlEvents) {
        event.visit([&](const auto& concreteEvent) {
            auto it = sfmlSubscribers.find(std::type_index(typeid(concreteEvent)));
            if (it != sfmlSubscribers.end()) {
                for (auto& callback : it->second) {
                    callback(event);
                }
            }
            });
    }

    customEvents.clear();
    sfmlEvents.clear();
}
