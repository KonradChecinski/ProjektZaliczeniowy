#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include<vector>
using namespace std;
using namespace sf;

namespace BreakOut
{
	class Paddle
	{
	public:
		Paddle(GameDataRef data);
		void MovePaddle(float dt);
		void SpawnPaddle();
		void DrawPaddle();


		const Sprite& GetSprite() const;


	private:
		GameDataRef _data;
		vector<Sprite> paddleSprites;
		Sprite* _paddle;

	};

}

