#include "Paddle.h"
#include"Definitions.h"
#include <iostream>
using namespace sf;

namespace BreakOut
{

	Paddle::Paddle(GameDataRef data) : _data(data)
	{
		_data->assets.LoadTexture("Paddle", PADDLE_FILEPATH);
	}


	void Paddle::SpawnPaddle()
	{

		Sprite sprite(_data->assets.GetTexture("Paddle"));
		sprite.setScale(0.7, 0.7);
		sprite.setPosition((SCREEN_WIDTH / 2) - (sprite.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.08));
		paddleSprites.push_back(sprite);

		


	}
	void Paddle::DrawPaddle()
	{


		for (int i = 0; i < paddleSprites.size(); i++)
		{
			_data->window.draw(paddleSprites.at(i));
		}

	}

	void Paddle::MovePaddle(float dt) {

		if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			for (int i = 0; i < paddleSprites.size(); i++)
			{
				//cout << paddleSprites.at(i).getPosition().x << endl;
				if (paddleSprites.at(i).getPosition().x > 0+5) {
					Vector2f position = paddleSprites.at(i).getPosition();
					float movement = SPEED_PADDLE * dt;
					paddleSprites.at(i).move(-movement, 0);
				}
				
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			for (int i = 0; i < paddleSprites.size(); i++)
			{
				//cout << paddleSprites.at(i).getPosition().x << endl;
				if (paddleSprites.at(i).getPosition().x < SCREEN_WIDTH- paddleSprites.at(i).getGlobalBounds().width -5) {
					Vector2f position = paddleSprites.at(i).getPosition();
					float movement = SPEED_PADDLE * dt;
					paddleSprites.at(i).move(movement, 0);
				}
			}
		}

	}

	const Sprite& Paddle::GetSprite() const {
		return paddleSprites.at(0);
	}
}
