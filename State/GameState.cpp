#include "GameState.h"


namespace Zero {
	GameState::GameState(std::shared_ptr<sf::RenderWindow> parentWindow)
	{
		window = parentWindow;

		Init();
	}

	void GameState::Init()
	{
		std::cout << "Initializing Game State" << std::endl;
	}

	void GameState::PollInput()
	{
		sf::Event event;

		while (window.lock()->pollEvent(event)) {
			switch (event.type)
			{
				case sf::Event::KeyPressed:

					if (event.key.code == sf::Keyboard::T) {
						std::cout << "T Key pressed from Game State" << std::endl;
					}
					break;

				case sf::Event::Closed:

					//TODO: This leaks memory and needs to be a bool to for the StateMachine to read to clean up
					window.lock()->close();

				default:
					break;
			}
		}
	}

	void GameState::Update(float dt)
	{
		PollInput();
		Draw(dt);
	}

	void GameState::Draw(float dt)
	{
		window.lock()->clear(sf::Color::Magenta);
		window.lock()->display();
	}
}