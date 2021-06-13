#pragma once
#include<SFML/Graphics.hpp>
#include"State.h"
#include"Game.h"
using namespace sf;


namespace BreakOut
{
	class SplashState: public State
	{
	public:
		SplashState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);

	private:
		GameDataRef _data;
		Clock _clock;
		Sprite _background;


	};

}

