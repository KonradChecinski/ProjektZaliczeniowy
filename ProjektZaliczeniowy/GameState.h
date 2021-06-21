#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include"State.h"
#include"Definitions.h"
#include"Brick.h"
#include"Ball.h"
#include"Paddle.h"
#include"Game.h"
#include"Collision.h"
#include"WinScreenState.h"
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
using namespace sf;

extern int Actual_Level;

namespace BreakOut
{
	

	class GameState : public State
	{
	public:
		GameState(GameDataRef data);
		GameState(GameDataRef data, int actualLevel);

		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);



		Vector2f movement{};
		Vector2f movementOrigin{};

		int Actual_Level = 3;

	private:
		int level;

		GameDataRef _data;
		Sprite _background;
		
		/*Sprite _paddle;*/

		Brick* brick;
		Ball* ball;
		Paddle* paddle;
		Collision collision;

		SoundBuffer soundBufferStart;
		Sound soundStart;

		
	};
	
	

}