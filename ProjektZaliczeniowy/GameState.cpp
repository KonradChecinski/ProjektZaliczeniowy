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
	int Actual_Level = 3;
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}



	void GameState::Init()
	{
		
		this->_data->assets.LoadTexture("Paddle", PADDLE_FILEPATH);
		this->_data->assets.LoadTexture("Brick", BRICK_FILEPATH);
		this->_data->assets.LoadTexture("Ball", BALL_FILEPATH);

		brick = new Brick(_data);
		ball = new Ball(_data);
		

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_paddle.setTexture(this->_data->assets.GetTexture("Paddle"));

		this->_paddle.setScale(0.7, 0.7);
		this->_paddle.setPosition((SCREEN_WIDTH / 2) - (this->_paddle.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2));
		

		brick->PrepareLevel(Actual_Level - 1);
		ball->SpawnBall();

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
		ball->MoveBall(dt);
	}





	void GameState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_paddle);
		brick->DrawBricks();
		ball->DrawBall();
		this->_data->window.display();


	}
}




