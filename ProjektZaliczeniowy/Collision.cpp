#include "Collision.h"
#include <iostream>
using namespace std;

namespace BreakOut
{
	Collision::Collision() {

	}


	bool Collision::CheckBrickCollision(Sprite ball, Sprite brick, Vector2f& movement) {
		Rect<float> rectBall = ball.getGlobalBounds();
		Rect<float> rectBrick = brick.getGlobalBounds();
		float x = movement.x, y = movement.y;

		if (rectBall.intersects(rectBrick)) {
			/*if (rectBall.left+ rectBall.width<=rectBrick.left) {
				x
			}
			else if (rectBall.left < rectBrick.left + (rectBrick.width / 2)) {

			}*/



			movement = { -x, -y };
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
			/*cout << "Paddle: " << rectPaddle.left << endl;
			cout << "Paddle width: " << rectPaddle.width << endl;
			cout << "Ball: " << rectBall.left << endl;*/
			/*		if (rectBall.left < rectPaddle.left + (1*rectPaddle.width/5))
					{
						movement = { -movement.y, -movement.y };

					}else if (rectBall.left < rectPaddle.left + (4 * rectPaddle.width / 5))
					{
						movement = { movement.x, -movement.y };

					}else if (rectBall.left < rectPaddle.left + rectPaddle.width)
					{
						movement = { movement.y, -movement.y };


					}*/



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


			//movement = { -movement.x, -movement.y };
			return true;
		}
		else {
			return false;
		}
	}

	bool Collision::CheckWallCollsion(Sprite wall, Vector2f& movement) {
		//cout << sprite1.getPosition().x << endl;
		if (wall.getPosition().x <= 0) {
			movement = { -movement.x, movement.y };
			return true;
		}
		if (wall.getPosition().x >= SCREEN_WIDTH - wall.getGlobalBounds().width) {
			movement = { -movement.x, movement.y };
			return true;
		}
		if (wall.getPosition().y <= 0) {
			movement = { movement.x, -movement.y };
			return true;
		}

		return false;
	}
}