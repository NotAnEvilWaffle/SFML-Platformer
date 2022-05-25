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
		sf::Vector2f position;
		sf::Vector2i coordinates;

		Transform() : position(0, 0) {};
	};

	struct Collider {
		
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

	struct RigidBody2D {
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
	};
};