#include "Brick.h"
#include"Definitions.h"
using namespace sf;

namespace BreakOut
{

	Brick::Brick(GameDataRef data) : _data( data )
	{
		
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
