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
	GameState::GameState(GameDataRef data) : _data(data)
	{
	}
	GameState::GameState(GameDataRef data, int actualLevel) : _data(data)
	{
		Actual_Level = actualLevel;
	}



	void GameState::Init()
	{
		movement = { 0,1 };
		movementOrigin = { 0,1 };
		this->_data->assets.LoadTexture("Paddle", PADDLE_FILEPATH);
		this->_data->assets.LoadTexture("Brick", BRICK_FILEPATH);
		this->_data->assets.LoadTexture("Ball", BALL_FILEPATH);



		soundBufferStart.loadFromFile(SOUND_START);
		soundStart.setBuffer(soundBufferStart);
		soundStart.setVolume(50.f);
		soundStart.play();

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
			//if (this->_data->input.IsSpriteClicked(_background, Mouse::Left, this->_data->window)) {
			//	
			//	//soundStart.play();
			//	this->_data->machine.AddState(StateRef(new WinScreenState(_data)), true);

			//	
			//}
			
		}
	}

	void GameState::Update(double dt)
	{
		
		
		vector<Sprite> brickSprites = brick->GetSprites();
		for (int i = 0; i < brickSprites.size(); i++)
		{
			if (collision.CheckBrickCollision(ball->GetSprite(), brickSprites.at(i), movement)) {
				brick->DeleteBrick(brickSprites.at(i), i);
				break;
			}
		}
		if (brickSprites.size() == 0) {
			this->_data->machine.AddState(StateRef(new WinScreenState(_data)), true);
		}

		collision.CheckPaddleCollision(ball->GetSprite(), paddle->GetSprite(), movement, movementOrigin);
		collision.CheckWallCollsion(ball->GetSprite(), movement);
		if (collision.CheckWallDownCollsion(ball->GetSprite())) {
			/*for (int i = 0; i < brickSprites.size();i=i)
			{
					brick->DeleteBrick(brickSprites.at(i), i);
			}*/
			brickSprites.clear();
			this->_data->machine.AddState(StateRef(new LoseScreenState(_data)), true);


		}



		ball->MoveBall(dt, movement);
		ball->SpeedBall(movement, movementOrigin);
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




