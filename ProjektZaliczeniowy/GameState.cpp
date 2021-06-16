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



	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Paddle", PADDLE_FILEPATH);
		this->_data->assets.LoadTexture("Brick", BRICK_FILEPATH);

		brick = new Brick(_data);

		//brick->SpawnBrick();
		

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
			if (this->_data->input.IsSpriteClicked(_background, Mouse::Left, this->_data->window)) {
				
				try {
					brick->PrepareLevel(Actual_Level-1);
				}
				catch(exception e) {
					this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				}
				
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




