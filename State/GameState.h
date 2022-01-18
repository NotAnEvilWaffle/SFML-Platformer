#pragma once
#include "State.h"
#include "../Systems/PlayerInputSystem.h"
#include <iostream>


namespace Zero {
	class GameState : public State
	{
	public:

		GameState(std::shared_ptr<sf::RenderWindow> parentWindow);

		void CreatePlayer(std::string path, short id);


		void Init();
		void PollInput();
		void Draw(float dt);
		void Update(float dt);

	private:


		std::unique_ptr<Entity> m_Player;
	};



}
