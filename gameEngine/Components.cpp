#include "Component.h"

/*
 * Implements core components that are not specific to any particular game.
 * Component declarations are located in Component.h.
 * Game-specific components should be implemented in separate files.
 */

HealthComponent::HealthComponent(int health) : health(health) {};

VelocityComponent::VelocityComponent(sf::Vector2f velocity) : velocity(velocity) {};

TransformComponent::TransformComponent(sf::Vector2f position, sf::Vector2f size) : position(position),
																				   rotation(0.0f), scale(1.0f, 1.0f), 
																				   size(size) {};

ColliderComponent::ColliderComponent(){};

TerrainColliderComponent::TerrainColliderComponent() {};

PlayerComponent::PlayerComponent(int playerId) : playerId(playerId) {};

RectangleComponent::RectangleComponent(sf::RectangleShape rectangle, sf::Vector2f size, sf::Color colour)
	: rectangle(rectangle), size(size), colour(colour) 
{
	this->rectangle.setSize(size);
	this->rectangle.setFillColor(colour);
}