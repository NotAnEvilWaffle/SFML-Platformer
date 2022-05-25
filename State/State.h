#pragma once

#include <SFML/Graphics.hpp>
#include "../Entity/Entity.h"
#include "../Components/Components.h"

namespace Zero {

	class Entity;
	class State
	{

	public:

		virtual void Init() = 0;
		virtual void PollInput() = 0;
		virtual void Draw(float dt) = 0;
		virtual void Update(float dt) = 0;

		virtual Entity CreateEmptyEntity(std::string path);



	protected:

		State(sf::RenderWindow& parentWindow) : window(parentWindow) {}

		sf::Event event;
		entt::registry m_Registry;
		sf::RenderWindow& window;

		




	private:

		friend class Entity;


	};
}

