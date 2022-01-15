#pragma once
#include "State/StateMachine.h"

namespace Zero {

	class Game
	{
	public:
		StateMachine machine;

		Game(int width, int height, std::string windowTitle);

		void Run();

	private:

		/*Yes this is bad and will be changed to actually use the framerate*/
		const float dt = 1.f / 60.f;
		sf::Clock m_Clock;

		std::shared_ptr<sf::RenderWindow> m_Window;


	};

}