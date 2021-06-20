#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Definitions.h"


using namespace sf;

namespace BreakOut
{
	class Collision
	{
	public:
		Collision();

		bool CheckSpriteCollision(Sprite sprite1, Sprite sprite2, Vector2f& movement);
		bool CheckPaddleCollision(Sprite sprite1, Sprite sprite2, Vector2f& movement);
		bool CheckWallCollsion(Sprite sprite1, Vector2f &movement);
	};

}