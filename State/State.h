#pragma once

#include <SFML/Graphics.hpp>
#include "../Entity/Entity.h"

namespace Zero {

	class Entity;
	class State
	{

	public:

		virtual void Init() = 0;
		virtual void PollInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;

		virtual Entity CreateEntity();



	protected:

		sf::Event event;

		entt::registry m_Registry;

		std::weak_ptr<sf::RenderWindow> window;




	private:




	};
}

