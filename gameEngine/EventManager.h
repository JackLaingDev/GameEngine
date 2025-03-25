#ifndef EventManager_H 
#define EventManager_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include <SFML/Window.hpp>
#include "Event.h"

class EventManager {
private:
    sf::Window* win;

    std::unordered_map<eventType, std::vector<std::function<void(const Event&)>>> customSubscribers;
    std::unordered_map<std::type_index, std::vector<std::function<void(const sf::Event&)>>> sfmlSubscribers;

    std::vector<Event> customEvents;
    std::vector<sf::Event> sfmlEvents;

public:
    EventManager(sf::Window* win);

    void enqueue(const Event& customEvent);
    void enqueue(const sf::Event& sfmlEvent);

    void pollSFMLEvents();

    void subscribe(eventType type, std::function<void(const Event&)> callback);

    template<typename TEventSubtype>
    void subscribe(std::function<void(const TEventSubtype&)> callback) {
        sfmlSubscribers[std::type_index(typeid(TEventSubtype))].push_back(
            [callback](const sf::Event& event) {
                if (const auto* concreteEvent = event.getIf<TEventSubtype>()) {
                    callback(*concreteEvent);
                }
            }
        );
    }

    void publish();
};

#endif
