#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include"State.h"
#include "Definitions.h"
#include"Brick.h"
#include"Game.h"
#include<SFML/Graphics.hpp>
using namespace sf;

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


		GameDataRef _data;
		Sprite _background;
		Sprite _paddle;
		Brick* brick;
	};
	
	

}