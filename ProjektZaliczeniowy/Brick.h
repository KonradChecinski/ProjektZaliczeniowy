#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include<vector>
using namespace std;
using namespace sf;

namespace BreakOut
{
	class Brick
	{
	public:
		Brick(GameDataRef data);
		void SpawnBrick();
		void DrawBricks();
	private:
		GameDataRef _data;
		vector<Sprite>brickSprites;

	};

}
