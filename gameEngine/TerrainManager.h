#ifndef TerrainManager_H 
#define TerrainManager_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


class TerrainManager {
private:

	std::vector<region> regions;

public:

	void addRegion(sf::Vector2f pos, sf::Vector2f size);
	std::vector<region> getRegions();

};

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


#endif 
