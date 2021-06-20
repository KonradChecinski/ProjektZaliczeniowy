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
		void MoveBall(float dt, Vector2f movement);
		void SpawnBall();
		void DrawBall();
		void SpeedBall(Vector2f& movement, Vector2f& movementOrigin);

		const Sprite& GetSprite() const;


	private:
		GameDataRef _data;
		vector<Sprite> ballSprites;
		Sprite *_ball;

		Clock _clockBall;


		Time time=seconds(9);

	};

}
