#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include"State.h"
using namespace sf;

namespace BreakOut
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);

	private:
		GameDataRef _data;
		Sprite _background;
		Sprite _playButton;
		Sprite _optionsButton;
		Sprite _exitButton;
		Sprite _title;

		
	};
}