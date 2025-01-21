#ifndef EventManager_H 
#define EventManager_H

#include <iostream> 
#include <functional>

#include "Event.h"


class EventManager {
private:
    // Map event types to a list of callbacks (subscribers)
    std::unordered_map<eventType, std::vector<std::function<void(const Event&)>>> subscribers;
    

public:

    std::vector<Event> events;
    // Subscribe a callback to an event type
    void subscribe(eventType type, std::function<void(const Event&)> callback);

    // Publish an event, invoking all callbacks for its type
    void publish();
};


#endif 
