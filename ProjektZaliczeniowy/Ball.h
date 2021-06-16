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
		void MoveBall(float dt);
		void SpawnBall();
		void DrawBall();

		const Sprite& GetSprite() const;


	private:
		GameDataRef _data;
		vector<Sprite> ballSprites;
		Sprite *_ball;

		Clock _clockBall;

	};

}
