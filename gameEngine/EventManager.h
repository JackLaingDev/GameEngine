#ifndef EventManager_H
#define EventManager_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include <SFML/Graphics.hpp> // For sf::RenderWindow and sf::Event
#include "Event.h" // Assuming this defines your custom Event class and eventType enum

class EventManager {
private:
    sf::RenderWindow* window;

    std::unordered_map<eventType, std::vector<std::function<void(const Event&)>>> customSubscribers;

    // CORRECTED: sfmlSubscribers now map type_index of the *specific SFML event struct* (e.g., sf::Event::KeyPressed)
    // to a vector of functions that accept the *base sf::Event&*.
    // The lambda in `subscribe` will use `event.getIf<TEventSubtype>()` and then call `callback(*concreteEvent)`.
    std::unordered_map<std::type_index, std::vector<std::function<void(const sf::Event&)>>> sfmlSubscribers;

    std::vector<Event> customEvents;
    std::vector<sf::Event> sfmlEvents; // Stores the raw sf::Event objects from pollEvent()

public:
    EventManager(sf::RenderWindow* win_ptr = nullptr);

    void enqueue(const Event& customEvent);
    void enqueue(const sf::Event& sfmlEvent); // Enqueues the full sf::Event object

    void subscribe(eventType type, std::function<void(const Event&)> callback);

    // CORRECTED: Template subscribe method for SFML 3.0 specific event structs
    template<typename TEventSubtype> // TEventSubtype will be like sf::Event::KeyPressed, sf::Event::MouseMoved
    void subscribe(std::function<void(const TEventSubtype&)> callback) {
        sfmlSubscribers[std::type_index(typeid(TEventSubtype))].push_back(
            [callback](const sf::Event& event) {
                // This lambda receives the base sf::Event.
                // It then tries to get the specific subtype using getIf<TEventSubtype>().
                if (const auto* concreteEvent = event.getIf<TEventSubtype>()) {
                    callback(*concreteEvent); // Calls the user's specific callback with the extracted struct
                }
            }
        );
    }

    void publish();
};

#endif