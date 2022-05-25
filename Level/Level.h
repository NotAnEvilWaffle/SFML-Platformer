#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <cstddef>
#include <iostream>

#include "SFML/Graphics/Rect.hpp"
#include "../Tile/Tile.h"
#include "../External/PugiXML/pugixml.hpp"

class GameState;
class Level
{
public:

	Level();

	// Creates a new Level object with a given name that corresponds EXACTLY to the tmx file name
	// Takes a reference to the game state that will be drawing it
	Level(std::string const levelName, sf::RenderWindow& window);

	~Level(){};

	void Update(float dt);
	void Draw(float dt);


private:

	std::string _levelName;

	std::vector<Tile*> _tileList;
	
	sf::Vector2i _mapSize;
	sf::Vector2i _tileSize;

	sf::Texture _texture;
};