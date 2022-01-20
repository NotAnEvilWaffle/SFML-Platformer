#include "PlayerInputSystem.h"
#include <memory>



namespace Zero {

	void PlayerInput(std::unique_ptr<Entity> const& player, const float dt)
	{

		if (player->HasComponent<RigidBody2D>()) {
			RigidBody2D& rb2d = player->GetComponent<RigidBody2D>();

			rb2d.velocity = sf::Vector2f(0.0f, 0.0f);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				rb2d.velocity -= sf::Vector2f(0.f, 200.f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				rb2d.velocity += sf::Vector2f(0.f, 200.f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				rb2d.velocity -= sf::Vector2f(200.f, 0.f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				rb2d.velocity += sf::Vector2f(200.f, 0.f);
		}
		

		

		player->UpdateMovement(dt);

	}
}