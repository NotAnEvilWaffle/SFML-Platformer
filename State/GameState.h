#pragma once
#include "State.h"
#include "../Systems/PlayerInputSystem.h"
#include "../Level/Level.h"
#include <iostream>


namespace Zero {
	class GameState : public State
	{
	public:

		GameState(sf::RenderWindow& parentWindow);

		void CreatePlayer(std::string path, short id);


		void Init();
		void PollInput();
		void Draw(float dt);
		void Update(float dt);

	private:


		Level* _level;
		std::unique_ptr<Entity> m_Player;
	};



}
