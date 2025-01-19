#ifndef Event_H 
#define Event_H

#include <iostream> 
#include <variant>

// Enum Classes
enum class eventType {
	takeDamage,
	collisionDetected,
	terrainCollisionDetected,
	keyPress,
	movePlayer
};

enum class Direction {
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// Structs
struct takeDamageData
{
	int damage;
};

struct collisionData
{

};

struct terrainCollisionData
{

};

struct keyPressData {
	char key;
};

struct movePlayerData
{
	Direction direction;
	float velocity;
};

// Classes
class Event {
private:


public:

	eventType type;

	// Event data types
	std::variant<takeDamageData,
		collisionData,
		terrainCollisionData,
		keyPressData,
		movePlayerData> data;

};


#endif 
