#include "GameState.h"
#include "../Systems/SpriteRendererSystem.h"


namespace Zero {
	GameState::GameState(sf::RenderWindow& parentWindow) : State(parentWindow)
	{
		Init();
	}

	void GameState::Init()
	{
		std::cout << "Initializing Game State" << std::endl;
		//CreatePlayer("Assets/Sprites/ltg.jpg", 1);

		_level = new Level("TestMap.tmx", window);
		
	}

	void GameState::PollInput()
	{
		sf::Event event;
	
		while (window.pollEvent(event)) {
			switch (event.type)
			{
				case sf::Event::Closed:
					//TODO: This leaks memory and needs to be a bool to for the StateMachine to read to clean up
					window.close();
					break;

				default:
					break;
			}
		}
	}

	void GameState::Update(float dt)
	{
		//PlayerInput(m_Player, dt);
		//_level.Update(dt);
		PollInput();
		Draw(dt);
	}

	void GameState::Draw(float dt)
	{
		window.clear(sf::Color::Black);
		_level->Draw(dt); 
		SpriteRender(m_Registry, window);
		


		window.display();
	}

	void GameState::CreatePlayer(std::string path, short id)
	{
		m_Player = std::make_unique<Entity>(m_Registry.create());
		m_Player->m_State = this;
		m_Player->m_StateRegistry = &m_Registry;
		m_Player->AddComponent<Transform>();
		m_Player->AddComponent<RigidBody2D>();
		m_Player->SetPosition(0, 0);
		m_Player->AddComponent<SpriteRenderer>(path);
		m_Player->AddComponent<Player>(id);
	}
}