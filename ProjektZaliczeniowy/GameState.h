#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include"State.h"
#include "Definitions.h"
#include"Brick.h"
#include"Ball.h"
#include"Game.h"
#include<SFML/Graphics.hpp>
using namespace sf;

extern int Actual_Level;

namespace BreakOut
{
	

	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);

	private:
		int level;

		GameDataRef _data;
		Sprite _background;
		Sprite _paddle;

		Brick* brick;
		Ball* ball;
	};
	
	

}