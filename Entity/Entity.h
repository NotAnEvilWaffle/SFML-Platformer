#pragma once
#include <memory>

#include "../entt.h"
#include "../State/State.h"
#include "../Components/Components.h"

namespace Zero {

	class State;
	class Entity
	{
	public:

		Entity(entt::entity entity);
		//Entity(const Entity& entity);
		~Entity() {};


		template<typename T, typename ... Args>
		T& AddComponent(Args&&... args) {
			return m_StateRegistry->emplace<T>(m_Entity, std::forward<Args>(args)...);
		}

		template <typename T>
		T& RemoveComponent();

		template <typename T>
		bool HasComponent();

		void SetPosition(int x, int y);
		void SetPosition(sf::Vector2i position);

	private:

		entt::entity m_Entity;
		entt::registry* m_StateRegistry;
		State* m_State;

		friend class State;

	};
}

