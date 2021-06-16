#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace BreakOut
{
	class Collision
	{
	public:
		Collision();

		bool CheckSpriteColision(Sprite sprite1, Sprite sprite2);

	};

}