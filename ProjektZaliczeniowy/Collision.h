#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Definitions.h"
#include "LoseScreenState.h"


using namespace sf;

namespace BreakOut
{
	class Collision
	{
	public:
		Collision();

		bool CheckBrickCollision(Sprite ball, Sprite brick, Vector2f& movement);
		bool CheckPaddleCollision(Sprite ball, Sprite paddle, Vector2f& movement, Vector2f& movementOrigin);
		bool CheckWallCollsion(Sprite ball, Vector2f &movement);
		bool CheckWallDownCollsion(Sprite ball);

	private:
		SoundBuffer soundBufferBrick;
		Sound soundBrick;
		SoundBuffer soundBufferPaddle;
		Sound soundPaddle;
	};

}