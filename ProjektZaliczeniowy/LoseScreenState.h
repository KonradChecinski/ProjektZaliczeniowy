#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"State.h"
#include"Game.h"
using namespace sf;


namespace BreakOut
{
	class LoseScreenState : public State
	{
	public:
		LoseScreenState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);

	private:
		GameDataRef _data;
		Sprite _gameOver;
		Sprite _mainMenu;
		Sprite _playButton;

		SoundBuffer soundBufferLose;
		Sound soundLose;

	};

}

