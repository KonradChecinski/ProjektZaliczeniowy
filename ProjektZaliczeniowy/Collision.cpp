#include "Collision.h"
#include <iostream>
using namespace std;

namespace BreakOut
{
	Collision::Collision() {
		soundBufferBrick.loadFromFile(SOUND_BRICK);
		soundBrick.setBuffer(soundBufferBrick);
		soundBrick.setVolume(50.f);

		soundBufferPaddle.loadFromFile(SOUND_PADDLE);
		soundPaddle.setBuffer(soundBufferPaddle);
		soundPaddle.setVolume(50.f);
		
	}


	bool Collision::CheckBrickCollision(Sprite ball, Sprite brick, Vector2f& movement) {
		Rect<float> rectBall = ball.getGlobalBounds();
		Rect<float> rectBrick = brick.getGlobalBounds();
		float x = movement.x, y = movement.y;

		if (rectBall.intersects(rectBrick)) {
			movement = { -x, -y };
			soundBrick.play();
			return true;
		}
		else {
			return false;
		}
	}

	bool Collision::CheckPaddleCollision(Sprite ball, Sprite paddle, Vector2f& movement, Vector2f& movementOrigin) {
		Rect<float> rectBall = ball.getGlobalBounds();
		Rect<float> rectPaddle = paddle.getGlobalBounds();

		float t{}, suma{}, x{}, y{};

		if (rectPaddle.intersects(rectBall)) {

			soundPaddle.play();
			if ((rectBall.left + rectBall.width/2) <= rectPaddle.left + (3 * rectPaddle.width / 7))
			{
				x = movementOrigin.x;
				x = abs(x);
				y = movementOrigin.y;
				y = abs(y);
				suma = sqrt((x * x) + (y * y));
				t = (rectPaddle.left + (rectPaddle.width / 2)) - (rectBall.left + rectBall.width / 2);
				t /= rectPaddle.width / 2;
				//cout << "t: " << t << endl;
				//cout << "suma: " << suma << endl << endl;
				x = abs(y) * t;
				y = sqrt(abs((suma * suma) - (x * x)));
				//y = abs(y)/t;
				//cout << "y: " << y << endl;
				//cout << "x: " << x << endl << endl;
				movement = { -x, -y };

			}
			else if ((rectBall.left + rectBall.width / 2) < rectPaddle.left + (4 * rectPaddle.width / 7))
			{
				movement = { movement.x, -movement.y };

			}
			else if ((rectBall.left + rectBall.width / 2) < rectPaddle.left + (7 * rectPaddle.width / 7))
			{
				
				x = movementOrigin.x;
				x = abs(x);
				y = movementOrigin.y;
				y = abs(y);
				suma = sqrt((x * x) + (y * y));
				t = (rectPaddle.left + (rectPaddle.width / 2)) - (rectBall.left + rectBall.width/2);
				//t = 120;
				t = abs(t);
				t /= rectPaddle.width / 2;
				//cout << "t: " << t << endl;
				//cout << "suma: " << suma << endl << endl;
				x = abs(y) * t;
				y = sqrt(abs((suma * suma) - (x * x)));
				//y = abs(y)/t;
				//cout << "y: " << y << endl;
				//cout << "x: " << x << endl << endl;
				movement = { x, -y };

			}

			return true;
		}
		else {
			return false;
		}
	}

	bool Collision::CheckWallCollsion(Sprite ball, Vector2f& movement) {
		//cout << sprite1.getPosition().x << endl;
		if (ball.getPosition().x <= 0) {
			movement = { -movement.x, movement.y };
			return true;
		}
		if (ball.getPosition().x >= SCREEN_WIDTH - ball.getGlobalBounds().width) {
			movement = { -movement.x, movement.y };
			return true;
		}
		if (ball.getPosition().y <= 0) {
			movement = { movement.x, -movement.y };
			return true;
		}
		

		return false;
	}

	bool Collision::CheckWallDownCollsion(Sprite ball) {
		if (ball.getPosition().y >= SCREEN_HEIGHT - ball.getGlobalBounds().height) {
			return true;
		}
		return false;
	}
}