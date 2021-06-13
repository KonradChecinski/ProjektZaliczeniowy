#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace BreakOut
{
	class InputManager
	{
	public:
		InputManager()
		{

		}
		~InputManager()
		{

		}
		bool IsSpriteClicked(Sprite obcject, Mouse::Button button, RenderWindow& window);
		Vector2i GetMousePosition(RenderWindow& window);
	};
}