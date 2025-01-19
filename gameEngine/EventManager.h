#ifndef EventManager_H 
#define EventManager_H

#include <iostream> 

#include "Event.h"


class EventManager {
private:

	std::vector<Event> eventsQueue;

public:

	EventManager() {}

	void subscribe(Event& event);
	void publish(Event& event);

};


#endif 
