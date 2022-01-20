#include "Game.h"


namespace Zero {
	Game::Game(int width, int height, std::string windowTitle) : machine(StateMachine())
	{
		m_Window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), windowTitle, sf::Style::Close);
		//m_Window->setFramerateLimit(500);


		/*This should be destroyed the moment the game goes out of scope
		  No need for dynamic allocation*/
		machine.PushState(std::make_unique<GameState>(m_Window));
	}
	void Game::UpdateDeltaTime()
	{
		this->dt = this->m_Clock.restart().asSeconds();
	}

	void Game::Run()
	{
		while (this->m_Window->isOpen()) {
			UpdateDeltaTime();
			machine.GetCurrentState()->Update(dt);
		}
	}
}