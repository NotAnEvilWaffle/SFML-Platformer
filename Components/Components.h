#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>




struct Component {

};

struct Transform : Component {
	sf::Vector2i position;

	Transform() = default;
	Transform() : position(0, 0) {}

};

struct SpriteRenderer : Component {
	sf::Texture tex;
	sf::Sprite sprite;
	std::string texPath;

	SpriteRenderer() 
	{
		if (!tex.loadFromFile(texPath)) {
			std::cout << "Error loading file" << std::endl;
		}
		else
		{
			sprite.setTexture(tex);
		}
	};
};
