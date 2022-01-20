#pragma once
#include <stack>
#include <memory>
#include "State.h"
#include "GameState.h"

namespace Zero {

	class StateMachine
	{

	public:

		StateMachine() {};
		virtual ~StateMachine() {};

		void PushState(std::unique_ptr<State> state);
		void PopState();
		void UpdateState(const float dt);
		std::unique_ptr<State>& GetCurrentState();


	protected:



	private:

		

		std::stack<std::unique_ptr<State>> m_StateStack;


	};

}