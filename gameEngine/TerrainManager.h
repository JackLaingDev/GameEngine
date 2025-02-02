#ifndef TerrainManager_H 
#define TerrainManager_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


class Region {
private:

public:

	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Color colour;
	sf::RectangleShape rect;

	Region(sf::Vector2f pos, sf::Vector2f size, sf::Color colour);

};


class TerrainManager {
private:

	

public:

	std::vector<Region> regions;

	TerrainManager();

	void addRegion(sf::Vector2f pos, sf::Vector2f size, sf::Color colour);

};




#endif 
