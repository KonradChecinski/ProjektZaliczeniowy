#include "GameState.h"
#include<sstream>
#include "Definitions.h"
#include "Levels.h"
#include"MainMenuState.h"

#include<iostream>
using namespace sf;
using namespace std;

namespace BreakOut
{
	int Actual_Level = 1;
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}



	void GameState::Init()
	{
		movement = { 0,1 };
		this->_data->assets.LoadTexture("Paddle", PADDLE_FILEPATH);
		this->_data->assets.LoadTexture("Brick", BRICK_FILEPATH);
		this->_data->assets.LoadTexture("Ball", BALL_FILEPATH);

		brick = new Brick(_data);
		ball = new Ball(_data);
		paddle = new Paddle(_data);
		

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		//this->_paddle.setTexture(this->_data->assets.GetTexture("Paddle"));

		//this->_paddle.setScale(0.7, 0.7);
		//this->_paddle.setPosition((SCREEN_WIDTH / 2) - (this->_paddle.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2));
		//

		brick->PrepareLevel(Actual_Level - 1);
		ball->SpawnBall();
		paddle->SpawnPaddle();

	}
	void GameState::HandleInput()
	{
		Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			/*if (this->_data->input.IsSpriteClicked(_background, Mouse::Left, this->_data->window)) {
				
				
				
			}*/
			
		}
	}

	void GameState::Update(double dt)
	{
		
		
		vector<Sprite> brickSprites = brick->GetSprites();
		for (int i = 0; i < brickSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision(ball->GetSprite(), brickSprites.at(i), movement)) {
				brick->DeleteBrick(brickSprites.at(i), i);
				break;
			}
		}

		collision.CheckWallCollsion(ball->GetSprite(), movement);
		collision.CheckPaddleCollision(ball->GetSprite(), paddle->GetSprite(), movement);
		







		ball->MoveBall(dt, movement);
		ball->SpeedBall(movement);
		paddle->MovePaddle(dt);
	}





	void GameState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		ball->DrawBall();
		brick->DrawBricks();
		paddle->DrawPaddle();
		this->_data->window.display();


	}
}




