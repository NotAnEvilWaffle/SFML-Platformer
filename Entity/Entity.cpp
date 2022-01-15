#include "Entity.h"
namespace Zero {
	Entity::Entity(entt::entity entity) : m_Entity(entity)
	{

	}

	template <typename T>
	T& Entity::AddComponent() {
		State::m_Registry.emplace<T>(m_Entity);
	}
}
