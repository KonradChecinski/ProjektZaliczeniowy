#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include"State.h"
using namespace sf;

namespace BreakOut
{
	class OptionsState : public State
	{
	public:
		OptionsState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);

	private:
		GameDataRef _data;
		Sprite _background;
		Sprite _back;
		Sprite _options1;
		Sprite _options2;


	};
}