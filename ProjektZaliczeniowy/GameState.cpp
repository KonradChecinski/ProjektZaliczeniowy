#include "GameState.h"
#include<sstream>
#include "Definitions.h"
#include<iostream>
using namespace sf;
using namespace std;

namespace BreakOut
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}



	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Paddle", PADDLE_FILEPATH);
		this->_data->assets.LoadTexture("Brick", BRICK_FILEPATH);

		brick = new Brick(_data);


		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_paddle.setTexture(this->_data->assets.GetTexture("Paddle"));


		this->_paddle.setPosition((SCREEN_WIDTH / 2) - (this->_paddle.getGlobalBounds().width / 2), this->_paddle.getGlobalBounds().height * 3.3);



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
		}
	}

	void GameState::Update(double dt)
	{
		
	}





	void GameState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_paddle);
		brick->DrawBricks();
		this->_data->window.display();


	}
}




