#pragma once

namespace BreakOut
{
	class State
	{
	public:
		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(double dt) = 0;
		virtual void Draw(double dt) = 0;
		virtual void Pause() 
		{

		}
		virtual void Resume()
		{

		}
	};
}