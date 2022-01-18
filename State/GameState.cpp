#include "GameState.h"
#include "../Systems/SpriteRendererSystem.h"
#include <tuple>


namespace Zero {
	GameState::GameState(std::shared_ptr<sf::RenderWindow> parentWindow)
	{
		window = parentWindow;

		Init();
	}

	void GameState::Init()
	{
		std::cout << "Initializing Game State" << std::endl;
		Entity player = CreatePlayer("Assets/Sprites/ltg.jpg", 1);
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
					if (event.key.code == sf::Keyboard::Right) {
						auto view = m_Registry.view<Transform>();
						view.each([&](auto& transform) {
							transform.position.x += 10;

						});
					}
					if (event.key.code == sf::Keyboard::Left) {
						auto view = m_Registry.view<Transform>();
						view.each([&](auto& transform) {
							transform.position.x -= 10;

						});
					}
					if (event.key.code == sf::Keyboard::Up) {
						auto view = m_Registry.view<Transform>();
						view.each([&](auto& transform) {
							transform.position.y -= 10;

						});
					}
					if (event.key.code == sf::Keyboard::Down) {
						auto view = m_Registry.view<Transform>();
						view.each([&](auto& transform) {
							transform.position.y += 10;

						});
					}
					break;

				case sf::Event::Closed:

					//TODO: This leaks memory and needs to be a bool to for the StateMachine to read to clean up
					window.lock()->close();
					break;


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
		window.lock()->clear(sf::Color::Black);
		SpriteRender(m_Registry, window);
		


		window.lock()->display();
	}
}