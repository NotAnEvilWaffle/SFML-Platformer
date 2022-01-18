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
		CreatePlayer("Assets/Sprites/ltg.jpg", 1);
	}

	void GameState::PollInput()
	{
		sf::Event event;
		PlayerInput(m_Player);

		

		while (window.lock()->pollEvent(event)) {
			switch (event.type)
			{
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

	void GameState::CreatePlayer(std::string path, short id)
	{
		m_Player = std::make_unique<Entity>(m_Registry.create());
		m_Player->m_State = this;
		m_Player->m_StateRegistry = &m_Registry;
		m_Player->AddComponent<Transform>();
		m_Player->SetPosition(0, 0);
		m_Player->AddComponent<SpriteRenderer>(path);
		m_Player->AddComponent<Player>(id);
	}
}