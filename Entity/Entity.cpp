#include "Entity.h"
namespace Zero {
	Entity::Entity(entt::entity entity) : m_Entity(entity), m_State(nullptr), m_StateRegistry(nullptr)
	{

	}

	void Entity::SetPosition(int x, int y)
	{
		Transform& transform = m_StateRegistry->get<Transform>(this->m_Entity);
		transform.position.x = x;
		transform.position.y = y;
	}

	void Entity::SetPosition(sf::Vector2i position)
	{
		m_StateRegistry->get<Transform>(this->m_Entity).position = position;
	}

	void Entity::Move(sf::Vector2i position) {
		m_StateRegistry->get<Transform>(this->m_Entity).position += position;
	}

	

}
