#include "State.h"

namespace Zero {
	Entity State::CreateEmptyEntity(std::string path)
	{
		Entity entity(m_Registry.create());
		entity.m_State = this;
		entity.m_StateRegistry = &m_Registry;
		entity.AddComponent<Transform>();
		entity.SetPosition(0, 0);
		
		return entity;
	}

	Entity State::CreatePlayer(std::string path, short id)
	{
		Entity entity(m_Registry.create());
		entity.m_State = this;
		entity.m_StateRegistry = &m_Registry;
		entity.AddComponent<Transform>();
		entity.SetPosition(0, 0);
		entity.AddComponent<SpriteRenderer>(path);
		entity.AddComponent<Player>(id);
		return entity;
	}
}
