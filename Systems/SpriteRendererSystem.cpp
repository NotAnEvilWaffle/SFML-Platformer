#include "SpriteRendererSystem.h"

namespace Zero {

	void SpriteRender(entt::registry& registry, sf::RenderWindow& window)
	{
		auto view = registry.view<SpriteRenderer, Transform>();
		view.each([&](auto& sprite, auto& transform) {

			sprite.sprite.setPosition(sf::Vector2f(transform.coordinates));
			window.draw(sprite.sprite);

		});
	}
}