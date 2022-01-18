#include "PlayerInputSystem.h"
#include <memory>



namespace Zero {

	void PlayerInput(std::unique_ptr<Entity> const& player)
	{
		const float speed = 1;
		sf::Vector2i v;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			v.y -= speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			v.y += speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			v.x -= speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			v.x += speed;
		player->Move(v);

	}
}