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
		Sprite _gameWin;
		Sprite _mainMenu;



	};

}



