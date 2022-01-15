#include "State.h"


namespace Zero {
	Entity State::CreateEntity()
	{
		Entity entity(m_Registry.create());
		entity.m_State = this;
		return entity;
	}
}
