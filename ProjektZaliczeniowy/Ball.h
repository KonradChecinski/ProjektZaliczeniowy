#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include<vector>
using namespace std;
using namespace sf;

namespace BreakOut
{
	class Ball
	{
	public:
		Ball(GameDataRef data);
		void SpawnBall(double width, double height);
		void DrawBall();
	private:
		GameDataRef _data;
		vector<Sprite> ballSprites;
		Sprite* _ball;

	};

}
