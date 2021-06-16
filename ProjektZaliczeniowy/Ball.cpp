#include "Ball.h"
#include"Definitions.h"
#include <iostream>
using namespace sf;

namespace BreakOut
{

	Ball::Ball(GameDataRef data) : _data(data)
	{
		_data->assets.LoadTexture("Ball", BALL_FILEPATH);
	}


	void Ball::SpawnBall()
	{

		Sprite sprite(_data->assets.GetTexture("Ball"));
		sprite.setScale(0.8, 0.8);
		sprite.setPosition(SCREEN_WIDTH / 2 - sprite.getGlobalBounds().width / 2, SCREEN_HEIGHT / 1.4);
		ballSprites.push_back(sprite);

		
	}
	void Ball::DrawBall()
	{


		for (int i = 0; i < ballSprites.size(); i++)
		{
			_data->window.draw(ballSprites.at(i));
		}

	}

	void Ball::MoveBall(float dt) {
		/*cout << _clockBall.getElapsedTime().asSeconds() << endl;*/
		if (_clockBall.getElapsedTime().asSeconds() > 2) {

				;
				for (int i = 0; i < ballSprites.size(); i++)
				{
					Vector2f position = ballSprites.at(i).getPosition();
					//cout << position.x << endl;
					float movement = SPEED_BALL * dt;

					//__ball.move(0, movement);
					//_ball.move(0, movement)
					ballSprites.at(i).move(0, movement);
				}
		}
		
	}

	const Sprite& Ball::GetSprite() const {
		return ballSprites.at(0);
	}
}
