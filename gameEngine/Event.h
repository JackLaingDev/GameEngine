#ifndef Event_H 
#define Event_H

#include <iostream> 
#include <variant>
#include <SFML/Graphics.hpp>

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
	sf::Keyboard::Key key;
};

struct movePlayerData
{
	Direction direction;
	sf::Vector2f velocity;
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
