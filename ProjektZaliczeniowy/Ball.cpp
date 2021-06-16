#include "Ball.h"
#include"Definitions.h"
#include"Levels.h"
#include <iostream>
#include"MainMenuState.h"
using namespace sf;

namespace BreakOut
{

	Ball::Ball(GameDataRef data) : _data(data)
	{
		_data->assets.LoadTexture("Brick", BRICK_FILEPATH);
	}
	void Ball::SpawnBall(double width, double height)
	{

		Sprite sprite(_data->assets.GetTexture("Brick"));
		float x = (float)(SCREEN_WIDTH / AMOUNT_OF_BRICK_IN_LINE) / (float)(sprite.getTexture()->getSize().x);
		sprite.setScale(x, x);
		sprite.setPosition((sprite.getGlobalBounds().width) * width, (sprite.getGlobalBounds().height) * height);
		ballSprites.push_back(sprite);
	}

	void Ball::DrawBall()
	{
		for (int i = 0; i < ballSprites.size(); i++)
		{
			_data->window.draw(ballSprites.at(i));
		}

	}

}
