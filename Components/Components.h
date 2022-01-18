#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>


namespace Zero {


	struct Player {
		int playerID;
		Player(int id) : playerID(id) {};
	};


	struct Transform {
		sf::Vector2i position;

		Transform() : position(0, 0) {};
	};

	struct SpriteRenderer {
		sf::Texture tex;
		sf::Sprite sprite;

		SpriteRenderer(std::string texPath)
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
};