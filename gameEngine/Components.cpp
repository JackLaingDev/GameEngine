#include "Component.h"

/*
 * Implements core components that are not specific to any particular game.
 * Component declarations are located in Component.h.
 * Game-specific components should be implemented in separate files.
 */

HealthComponent::HealthComponent(int health) : health(health) {};

VelocityComponent::VelocityComponent(float velocity) : velocity(velocity) {};

TransformComponent::TransformComponent(float x, float y) : position(x, y), rotation(0.0f), scale(1.0f, 1.0f) {};

ColliderComponent::ColliderComponent(float x, float y, int width, int height) : x(x), y(y), width(width), height(height) {};

void TerrainColliderComponent::addRegion(float x, float y, float width, float height)
{
	Region region = Region(x, y, width, height);
	regions.push_back(std::make_unique<Region>(region));
}