#include "Tile.h"

Tile::Tile(sf::Texture& tex, sf::Vector2i tilesetCoords, sf::Vector2i screenCoords, sf::Vector2i size, sf::RenderWindow& window) : _window(window)
{
	_tileSet = &tex;
	_tilesetCoords = tilesetCoords;
	_screenCoords = screenCoords;
	_size = size;

	_sprite.setTexture(*_tileSet);
	_sprite.setTextureRect(sf::IntRect(_tilesetCoords.x, _tilesetCoords.y, _size.x, _size.y));

	_sprite.setPosition(sf::Vector2f(_screenCoords.x * 2, _screenCoords.y * 2));
	_sprite.setScale(2,2); 

}

void Tile::Draw(float dt)
{
	_window.draw(_sprite);
}