#pragma once
#include "State/StateMachine.h"

namespace Zero {

	class Game
	{
	public:
		StateMachine machine;

		Game(int width, int height, std::string windowTitle);

		~Game()
		{
			delete m_Window;
		}

		void UpdateDeltaTime();

		void Run();

	private:

		float dt;
		sf::Clock m_Clock;

		sf::RenderWindow* m_Window;


	};

}