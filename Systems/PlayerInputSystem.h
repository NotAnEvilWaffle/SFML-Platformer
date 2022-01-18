#pragma once
#include "SFML/System/Vector2.hpp"
#include <SFML/Window/Keyboard.hpp>
#include "../Entity/Entity.h"


namespace Zero {

	void PlayerInput(std::unique_ptr<Entity> const& player);

}
