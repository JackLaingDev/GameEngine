#include "TerrainManager.h"

TerrainManager::TerrainManager()
{
}

void TerrainManager::addRegion(sf::Vector2f pos, sf::Vector2f size, sf::Color colour)
{
	regions.emplace_back(pos, size, colour);
}




Region::Region(sf::Vector2f pos, sf::Vector2f size, sf::Color colour) : pos(pos), size(size), colour(colour)
{
	rect.setSize(size);
	rect.setPosition(pos);
	rect.setFillColor(colour);
}

