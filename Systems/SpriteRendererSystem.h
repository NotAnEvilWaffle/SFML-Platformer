#pragma once
#include "../entt.h"
#include "../Components/Components.h"

namespace Zero {
	void SpriteRender(entt::registry& registry, std::weak_ptr<sf::RenderWindow>& window);
}
