#include "Collision.h"
#include <iostream>
using namespace std;

namespace BreakOut
{
	Collision::Collision() {

	}


	bool Collision::CheckSpriteCollision(Sprite sprite1, Sprite sprite2, Vector2f& movement) {
		Rect<float> rect1 = sprite1.getGlobalBounds();
		Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2)) {
			movement = { -movement.x, -movement.y };
			return true;
		}
		else {
			return false;
		}
	}

	bool Collision::CheckPaddleCollision(Sprite ball, Sprite paddle, Vector2f& movement) {
		Rect<float> rectBall = ball.getGlobalBounds();
		Rect<float> rectPaddle = paddle.getGlobalBounds();

		

		if (rectPaddle.intersects(rectBall)) {
			/*cout << "Paddle: " << rectPaddle.left << endl;
			cout << "Paddle width: " << rectPaddle.width << endl;
			cout << "Ball: " << rectBall.left << endl;*/
			if (rectBall.left < rectPaddle.left + (1*rectPaddle.width/5))
			{
				/*if(movement.x > 0)	movement = { -movement.x, -movement.y };
				else movement = { movement.x, -movement.y };*/

				//cout << "ruch: " << "1" << endl;

				movement = { -movement.y, -movement.y };

			}else if (rectBall.left < rectPaddle.left + (4 * rectPaddle.width / 5))
			{
				//movement = { -movement.x, -movement.y };
				//cout << "ruch: " << "2" << endl;

				movement = { movement.x, -movement.y };

			}else if (rectBall.left < rectPaddle.left + rectPaddle.width)
			{
				/*if (movement.x > 0)	movement = { movement.x, -movement.y };
				else movement = { -movement.x, -movement.y };
				cout << "ruch: " << "3" << endl;*/

				movement = { movement.y, -movement.y };


			}

			//movement = { -movement.x, -movement.y };
			return true;
		}
		else {
			return false;
		}
	}

	bool Collision::CheckWallCollsion(Sprite sprite1, Vector2f &movement){
		//cout << sprite1.getPosition().x << endl;
		if (sprite1.getPosition().x <= 0) {
			movement = {-movement.x, movement.y};
			return true;
		}
		if (sprite1.getPosition().x >= SCREEN_WIDTH-sprite1.getGlobalBounds().width) {
			movement = { -movement.x, movement.y };
			return true;
		}
		if (sprite1.getPosition().y <= 0) {
			movement = { movement.x, -movement.y };
			return true;
		}

		return false;
	}
}