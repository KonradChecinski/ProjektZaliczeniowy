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
		void SpawnBrick(double width, double height);
		void DrawBricks();
		void DeleteBrick(Sprite sprite,int i);
		void PrepareLevel(int level);
		const vector<Sprite> &GetSprites() const;
	private:
		GameDataRef _data;
		vector<Sprite> brickSprites;
		Sprite *_brick;

	};

}
