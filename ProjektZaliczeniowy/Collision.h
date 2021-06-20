#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Definitions.h"


using namespace sf;

namespace BreakOut
{
	class Collision
	{
	public:
		Collision();

		bool CheckBrickCollision(Sprite ball, Sprite brick, Vector2f& movement);
		bool CheckPaddleCollision(Sprite ball, Sprite paddle, Vector2f& movement, Vector2f& movementOrigin);
		bool CheckWallCollsion(Sprite wall, Vector2f &movement);
	};

}