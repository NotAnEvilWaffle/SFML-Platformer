#include "SpriteRendererSystem.h"

namespace Zero {

	void SpriteRender(entt::registry& registry, std::weak_ptr<sf::RenderWindow>& window)
	{
		auto view = registry.view<SpriteRenderer, Transform>();
		view.each([&](auto& sprite, auto& transform) {

			sprite.sprite.setPosition(sf::Vector2f(transform.coordinates));
			window.lock()->draw(sprite.sprite);

		});
	}
}