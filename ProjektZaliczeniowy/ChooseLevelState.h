#pragma once
#include<SFML/Graphics.hpp>
#include"State.h"
#include"Game.h"
using namespace sf;


namespace BreakOut
{
	class ChooseLevelState : public State
	{
	public:
		ChooseLevelState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);

	private:
		GameDataRef _data;
		Sprite _background;
		Sprite _play1;
		Sprite _play2;
		Sprite _play3;
		Sprite _play4;
		Sprite _back;
		Sprite _play1Image;
		Sprite _play2Image;
		Sprite _play3Image;
		Sprite _play4Image;




	};

}



