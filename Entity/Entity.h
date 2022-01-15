#pragma once
#include <memory>

#include "../entt.h"
#include "../State/State.h"
namespace Zero {

	class State;
	class Entity
	{
	public:

		Entity(entt::entity entity);
		//Entity(const Entity& entity);
		~Entity() {};


		template <typename T>
		T& AddComponent();

		template <typename T>
		T& RemoveComponent();

		template <typename T>
		bool HasComponent();

	private:

		entt::entity m_Entity;
		State* m_State;

		friend class State;

	};
}

