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

	void Ball::MoveBall(float dt, Vector2f movement) {
		/*cout << _clockBall.getElapsedTime().asSeconds() << endl;*/
		if (_clockBall.getElapsedTime().asSeconds() > 2) {
				for (int i = 0; i < ballSprites.size(); i++)
				{
					Vector2f position = ballSprites.at(i).getPosition();
					movement.x = movement.x * SPEED_BALL * dt;
					movement.y = movement.y * SPEED_BALL * dt;
					//cout << "X: " << movement.x << " Y: " << movement.y << endl;
					ballSprites.at(i).move(movement);
				}
		}
		
	}

	void Ball::SpeedBall(Vector2f& movement, Vector2f& movementOrigin) {
		if (_clockBall.getElapsedTime().asSeconds() > time.asSeconds()) {
			time = time + seconds(6);
			movement.x = movement.x * 1.01;
			movement.y = movement.y * 1.01;
			movementOrigin.x = movementOrigin.x * 1.01;
			movementOrigin.y = movementOrigin.y * 1.01;
			cout << "speed!!!" << endl;
		}
	}


	const Sprite& Ball::GetSprite() const {
		return ballSprites.at(0);
	}
}
