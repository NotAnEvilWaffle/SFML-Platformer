#include "Entity.h"
#include <cmath>
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

	void Entity::SetPosition(sf::Vector2f position)
	{
		m_StateRegistry->get<Transform>(this->m_Entity).position = position;
	}

	void Entity::UpdateMovement(const float dt) {

		if (m_StateRegistry->any_of<RigidBody2D>(this->m_Entity)) {

			Transform& transform = m_StateRegistry->get<Transform>(this->m_Entity);
			RigidBody2D& rb2d = m_StateRegistry->get<RigidBody2D>(this->m_Entity);

			rb2d.velocity += rb2d.acceleration;

			transform.position += rb2d.velocity * dt;

			transform.coordinates.x = std::round(transform.position.x);
			transform.coordinates.y = std::round(transform.position.y);
			std::cout << transform.coordinates.x << " " << transform.coordinates.y << std::endl;
		}


	}

	

}
