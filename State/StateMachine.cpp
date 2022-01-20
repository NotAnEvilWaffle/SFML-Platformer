#include "StateMachine.h"

namespace Zero {
	void StateMachine::PushState(std::unique_ptr<State> state)
	{
		m_StateStack.push(std::move(state));
	}

	void StateMachine::UpdateState(const float dt) 
	{
		m_StateStack.top()->Update(dt);
	}

	std::unique_ptr<State>& StateMachine::GetCurrentState() 
	{
		return this->m_StateStack.top();
	}
}