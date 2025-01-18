#ifndef Component_H 
#define Component_H

#include <iostream>
#include <SFML/System.hpp>

// Class declaration
class Component {
private:


public:
	virtual ~Component() noexcept = default;

};

// Public inheritance to allow usage of ~Component
// Health Component to store entity health
class HealthComponent : public Component {
private:

public:
	int health;

	HealthComponent(int health);
};

//
class VelocityComponent : public Component {
private: 

public:
	float velocity;

	VelocityComponent(float velocity);

};

//
class TransformComponent : public Component {
public:
	sf::Vector2f position;
	float rotation; // In degrees (SFML uses degrees)
	sf::Vector2f scale;

	TransformComponent() : position(0.0f, 0.0f), rotation(0.0f), scale(1.0f, 1.0f) {}
	TransformComponent(float x, float y) : position(x, y), rotation(0.0f), scale(1.0f, 1.0f) {}
};

//
class ColliderComponent : public Component {
private:

public:
	float x, y;
	float width, height;

	ColliderComponent(float x, float y, int width, int height);

};

//
class TerrainColliderComponent : public Component {
private:

public:
	struct Region {
		float x, y;
		float width, height;

		Region(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {};
		~Region() {}
	};

	std::vector<Region> regions;

	~TerrainColliderComponent() noexcept override {}

	void addRegion(float x, float y, float width, float height);

};


#endif 
