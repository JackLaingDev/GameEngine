#ifndef EventManager_H 
#define EventManager_H

#include <iostream> 
#include <functional>

#include "Event.h"


class EventManager {
private:
    // Map event types to a list of callbacks (subscribers)
    std::unordered_map<eventType, std::vector<std::function<void(const Event&)>>> customSubscribers;
    std::unordered_map<sf::Event, std::vector<std::function<void(const sf::Event&)>>> SFMLSubscribers;
    sf::Window* win;

    // Event queues
    std::vector<Event> customEvents;
    std::vector<sf::Event> SFMLEvents;

public:

    EventManager(sf::Window* win);

    void enqueue(const Event& customEvent);
    void enqueue(const sf::Event& sfmlEvent);

    // Func to poll SFML events
    void pollSFMLEvents();

    // Subscribe a callback to an event type
    void subscribe(eventType type, std::function<void(const Event&)> callback);
    void subscribe(sf::Event type, std::function<void(const sf::Event&)> callback);

    // Publish an event, invoking all callbacks for its type
    void publish();
};


#endif 
