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

public:

	sf::RectangleShape rect;

	region(sf::Vector2f pos, sf::Vector2f size, sf::Color colour);

};


class TerrainManager {
private:

	

public:

	std::vector<region> regions;

	TerrainManager();

	void addRegion(sf::Vector2f pos, sf::Vector2f size, sf::Color colour);

};




#endif 
