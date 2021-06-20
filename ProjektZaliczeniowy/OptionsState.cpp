#include "OptionsState.h"
#include<sstream>
#include "Definitions.h"
#include<iostream>
#include"MainMenuState.h"
#include"GameState.h"
using namespace sf;
using namespace std;

namespace BreakOut
{
	OptionsState::OptionsState(GameDataRef data) : _data(data)
	{

	}

	void OptionsState::Init()
	{
		this->_data->assets.LoadTexture("Options_1", OPTIONS_OPTIONS1_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Options_2", OPTIONS_OPTIONS2_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Back", OPTIONS_BACK_BUTTON_FILEPATH);
		//this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON_FILEPATH);


		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_back.setTexture(this->_data->assets.GetTexture("Back"));
		this->_options1.setTexture(this->_data->assets.GetTexture("Options_1"));
		this->_options2.setTexture(this->_data->assets.GetTexture("Options_2"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));


		this->_options1.setPosition((SCREEN_WIDTH / 2) - (this->_options1.getGlobalBounds().width / 2), this->_options1.getGlobalBounds().height * 0.6);
		this->_options2.setPosition((SCREEN_WIDTH / 2) - (this->_options2.getGlobalBounds().width / 2), (this->_options2.getGlobalBounds().height * 1.8));
		this->_back.setPosition((SCREEN_WIDTH / 2) - (this->_back.getGlobalBounds().width / 2), (this->_back.getGlobalBounds().height * 5.4));
		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), (this->_playButton.getGlobalBounds().height * 6.8));
	}
	void OptionsState::HandleInput()
	{
		Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_back, Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_playButton, Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}

		}
	}

	void OptionsState::Update(double dt)
	{

	}

	void OptionsState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_options1);
		this->_data->window.draw(this->_options2);
		this->_data->window.draw(this->_back);
		this->_data->window.draw(this->_playButton);
		this->_data->window.display();
	}
}
