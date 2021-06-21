#include "MainMenuState.h"
#include "ChooseLevelState.h"
#include<sstream>
#include "Definitions.h"
#include<iostream>
#include"GameState.h"
#include"OptionsState.h"
#include"LoseScreenState.h"
using namespace sf;
using namespace std;

namespace BreakOut
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Background", MAIN_MANU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Options Button", MAIN_MENU_OPTIONS_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Exit Button", MAIN_MENU_EXIT_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Title", MAIN_MENU_TITLE_FILEPATH);


		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_optionsButton.setTexture(this->_data->assets.GetTexture("Options Button"));
		this->_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
		this->_title.setTexture(this->_data->assets.GetTexture("Title"));

		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), this->_playButton.getGlobalBounds().height * 3.0);
		this->_optionsButton.setPosition((SCREEN_WIDTH / 2) - (this->_optionsButton.getGlobalBounds().width / 2), (this->_optionsButton.getGlobalBounds().height * 4.5));
		this->_exitButton.setPosition((SCREEN_WIDTH / 2) - (this->_exitButton.getGlobalBounds().width / 2), (this->_exitButton.getGlobalBounds().height * 6.0));
		this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.9);
	}
	void MainMenuState::HandleInput()
	{
		Event event;
		while (this->_data->window.pollEvent(event))
		{

			if (Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			else if (this->_data->input.IsSpriteClicked(this->_playButton, Mouse::Left, this->_data->window))
			{
				//this->_data->machine.AddState(StateRef(new GameState(_data)), true);
				this->_data->machine.AddState(StateRef(new ChooseLevelState(_data)), true);
			}
			else if (this->_data->input.IsSpriteClicked(this->_optionsButton, Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new OptionsState(_data)), true);
			}
			else if (this->_data->input.IsSpriteClicked(this->_exitButton, Mouse::Left, this->_data->window))
			{
				this->_data->window.close();
			}

		}
	}

	void MainMenuState::Update(double dt)
	{

	}

	void MainMenuState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_optionsButton);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_exitButton);

		this->_data->window.display();
	}
}
