#pragma once

#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile();
	Tile(sf::Texture& tex, sf::Vector2i tilesetCoords, sf::Vector2i screenCoords, sf::Vector2i size, sf::RenderWindow& window);

	~Tile()
	{

	};

	void Draw(float dt);
	void Update(float dt);

protected:




private:

	sf::Texture* _tileSet;
	sf::Sprite _sprite;

	sf::Vector2i _tilesetCoords;
	sf::Vector2i _screenCoords;
	sf::Vector2i _size;

	sf::RenderWindow& _window;
};