#include "TerrainManager.h"

TerrainManager::TerrainManager()
{
}

void TerrainManager::addRegion(sf::Vector2f pos, sf::Vector2f size, sf::Color colour)
{
	regions.emplace_back(pos, size, colour);
}

std::vector<region> TerrainManager::getRegions()
{
	return regions;
}



region::region(sf::Vector2f pos, sf::Vector2f size, sf::Color colour) : pos(pos), size(size), colour(colour)
{
	rect.setSize(size);
	rect.setPosition(pos);
	rect.setFillColor(colour);
}

sf::RectangleShape region::getRect()
{
	return rect;
}
