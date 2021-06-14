#include "Brick.h"
#include"Definitions.h"
using namespace sf;

namespace BreakOut
{

	Brick::Brick(GameDataRef data) : _data(data)
	{
		Sprite sprite(_data->assets.GetTexture("BRICK"));
		sprite.setPosition(_data->window.getSize().x*2, _data->window.getSize().y *0.8);
	}
	void SpawnBrick()
	{

	}

	void Brick::DrawBricks()
	{
		for (int i = 0; i < brickSprites.size(); i++)
		{
			_data->window.draw(brickSprites.at(i));
		}
	}
}
