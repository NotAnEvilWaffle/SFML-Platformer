#pragma once
#include "State.h"
#include <iostream>


namespace Zero {
	class GameState : public State
	{
	public:

		GameState(std::shared_ptr<sf::RenderWindow> parentWindow);

		void Init();
		void PollInput();
		void Update(float dt);
		void Draw(float dt);
	};
}
