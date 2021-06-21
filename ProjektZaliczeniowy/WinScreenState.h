#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"State.h"
#include"Game.h"
using namespace sf;


namespace BreakOut
{
	class WinScreenState : public State
	{
	public:
		WinScreenState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);

	private:
		GameDataRef _data;
		Sprite _gameWin;
		Sprite _mainMenu;

		SoundBuffer soundBufferWin;
		Sound soundWin;

	};

}



