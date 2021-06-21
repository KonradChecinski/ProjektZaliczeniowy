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
		this->_data->assets.LoadTexture("Game Win", WIN_SCREEN_GAME_WIN_FILEPATH);
		this->_data->assets.LoadTexture("Main Menu", MAIN_MENU_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON_FILEPATH);


		//this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_gameWin.setTexture(this->_data->assets.GetTexture("Game Win"));
		this->_mainMenu.setTexture(this->_data->assets.GetTexture("Main Menu"));

		this->_gameWin.setScale(0.8, 0.8);


		this->_gameWin.setPosition((SCREEN_WIDTH / 2) - (this->_gameWin.getGlobalBounds().width / 2), this->_gameWin.getGlobalBounds().height * 0.4);
		this->_mainMenu.setPosition((SCREEN_WIDTH / 2) - (this->_mainMenu.getGlobalBounds().width / 2), (this->_mainMenu.getGlobalBounds().height * 6.5));
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
			if (this->_data->input.IsSpriteClicked(this->_mainMenu, Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

		}
	}

	void ChooseLevelState::Update(double dt)
	{

	}

	void ChooseLevelState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_gameWin);
		this->_data->window.draw(this->_mainMenu);
		this->_data->window.display();
	}
}
