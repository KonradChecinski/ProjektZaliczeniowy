#include "ChooseLevelState.h"
#include<sstream>
#include "Definitions.h"
#include<iostream>
#include"MainMenuState.h"
#include"GameState.h"
using namespace sf;
using namespace std;

namespace BreakOut
{
	ChooseLevelState::ChooseLevelState(GameDataRef data) : _data(data)
	{

	}

	void ChooseLevelState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu", MAIN_MENU_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Play 1", CHOOSE_SCREEN_LEVEL_1_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Play 2", CHOOSE_SCREEN_LEVEL_2_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Play 3", CHOOSE_SCREEN_LEVEL_3_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Play 4", CHOOSE_SCREEN_LEVEL_4_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Play 1 Image", CHOOSE_SCREEN_LEVEL_1_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Play 2 Image", CHOOSE_SCREEN_LEVEL_2_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Play 3 Image", CHOOSE_SCREEN_LEVEL_3_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Play 4 Image", CHOOSE_SCREEN_LEVEL_4_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Back", OPTIONS_BACK_BUTTON_FILEPATH);



		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_play1.setTexture(this->_data->assets.GetTexture("Play 1"));
		this->_play2.setTexture(this->_data->assets.GetTexture("Play 2"));
		this->_play3.setTexture(this->_data->assets.GetTexture("Play 3"));
		this->_play4.setTexture(this->_data->assets.GetTexture("Play 4"));
		this->_play1Image.setTexture(this->_data->assets.GetTexture("Play 1 Image"));
		this->_play2Image.setTexture(this->_data->assets.GetTexture("Play 2 Image"));
		this->_play3Image.setTexture(this->_data->assets.GetTexture("Play 3 Image"));
		this->_play4Image.setTexture(this->_data->assets.GetTexture("Play 4 Image"));
		this->_back.setTexture(this->_data->assets.GetTexture("Back"));
		

		/*_play1.setScale(0.8, 0.8);
		_play2.setScale(0.8, 0.8);
		_play3.setScale(0.8, 0.8);
		_play4.setScale(0.8, 0.8);*/
		/*_play1Image.setScale(0.8, 0.8);
		_play2Image.setScale(0.8, 0.8);
		_play3Image.setScale(0.8, 0.8);
		_play4Image.setScale(0.8, 0.8);*/



		this->_play1Image.setPosition((SCREEN_WIDTH * 0.2), SCREEN_HEIGHT * 0.05);
		this->_play1.setPosition((SCREEN_WIDTH * 0.2), SCREEN_HEIGHT * 0.05 + _play1Image.getGlobalBounds().height);

		this->_play2Image.setPosition((SCREEN_WIDTH * 0.8) - _play2Image.getGlobalBounds().width, SCREEN_HEIGHT * 0.05);
		this->_play2.setPosition((SCREEN_WIDTH * 0.8) - _play2Image.getGlobalBounds().width, SCREEN_HEIGHT * 0.05 + _play2Image.getGlobalBounds().height);

		this->_play3Image.setPosition((SCREEN_WIDTH * 0.2), SCREEN_HEIGHT * 0.45);
		this->_play3.setPosition((SCREEN_WIDTH * 0.2), SCREEN_HEIGHT * 0.45 + _play3Image.getGlobalBounds().height);

		this->_play4Image.setPosition((SCREEN_WIDTH * 0.8) - _play4Image.getGlobalBounds().width, SCREEN_HEIGHT * 0.45);
		this->_play4.setPosition((SCREEN_WIDTH * 0.8) - _play4Image.getGlobalBounds().width, SCREEN_HEIGHT * 0.45 + _play3Image.getGlobalBounds().height);

		this->_back.setPosition((SCREEN_WIDTH / 2) - (this->_back.getGlobalBounds().width / 2), SCREEN_HEIGHT - (this->_back.getGlobalBounds().height * 1.2));

	}
	void ChooseLevelState::HandleInput()
	{
		Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_play1, Mouse::Left, this->_data->window))
			{
				//this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				this->_data->machine.AddState(StateRef(new GameState(_data, 1)), true);

			}
			if (this->_data->input.IsSpriteClicked(this->_play2, Mouse::Left, this->_data->window))
			{
	
				this->_data->machine.AddState(StateRef(new GameState(_data, 2)), true);

			}
			if (this->_data->input.IsSpriteClicked(this->_play3, Mouse::Left, this->_data->window))
			{
		
				this->_data->machine.AddState(StateRef(new GameState(_data, 3)), true);

			}
			if (this->_data->input.IsSpriteClicked(this->_play4, Mouse::Left, this->_data->window))
			{
	
				this->_data->machine.AddState(StateRef(new GameState(_data, 4)), true);

			}

		}
	}

	void ChooseLevelState::Update(double dt)
	{

	}

	void ChooseLevelState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_play1);
		this->_data->window.draw(this->_play2);
		this->_data->window.draw(this->_play3);
		this->_data->window.draw(this->_play4);
		this->_data->window.draw(this->_play1Image);
		this->_data->window.draw(this->_play2Image);
		this->_data->window.draw(this->_play3Image);
		this->_data->window.draw(this->_play4Image);
		this->_data->window.draw(this->_back);
		this->_data->window.display();
	}
}
