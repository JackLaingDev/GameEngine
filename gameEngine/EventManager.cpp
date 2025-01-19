#include "EventManager.h"

void EventManager::subscribe(Event& event)
{
	eventsQueue.push_back(event);
}

void EventManager::publish(Event& event)
{
	auto eventType = event.type;
	auto eventData = event.data;

	switch (eventType)
	{
	case eventType::takeDamage:
		// Pass data to necessary system
		break;
	case eventType::collisionDetected:
		// Pass data to necessary system
		break;
	case eventType::terrainCollisionDetected:
		// Pass data to necessary system
		break;
	case eventType::keyPress:
		// Pass data to necessary system
		break;
	case eventType::movePlayer:
		// Pass data to necessary system
		break;
	default:
		break;
	}

}
