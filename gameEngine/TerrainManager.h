#ifndef TerrainManager_H 
#define TerrainManager_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


class region {
private:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Color colour;
	sf::RectangleShape rect;

public:

	region(sf::Vector2f pos, sf::Vector2f size, sf::Color colour);

	sf::RectangleShape getRect();

};


class TerrainManager {
private:

	std::vector<region> regions;

public:

	TerrainManager();

	void addRegion(sf::Vector2f pos, sf::Vector2f size, sf::Color colour);
	std::vector<region> getRegions();

};




#endif 
