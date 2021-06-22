#include "LoseScreenState.h"
#include<sstream>
#include "Definitions.h"
#include<iostream>
#include"MainMenuState.h"
#include"ChooseLevelState.h"
using namespace sf;
using namespace std;

namespace BreakOut
{
	LoseScreenState::LoseScreenState(GameDataRef data) : _data(data)
	{

	}

	void LoseScreenState::Init()
	{
		this->_data->assets.LoadTexture("Game Over", LOSE_SCREEN_GAME_OVER_FILEPATH);
		this->_data->assets.LoadTexture("Main Menu", MAIN_MENU_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", LOSE_SCREEN_PLAY_AGAIN_FILEPATH);


		//this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_gameOver.setTexture(this->_data->assets.GetTexture("Game Over"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_mainMenu.setTexture(this->_data->assets.GetTexture("Main Menu"));

		this->_gameOver.setScale(0.8, 0.8);


		this->_gameOver.setPosition((SCREEN_WIDTH / 2) - (this->_gameOver.getGlobalBounds().width / 2), this->_gameOver.getGlobalBounds().height * 0.6);
		this->_mainMenu.setPosition((SCREEN_WIDTH / 2) - (this->_mainMenu.getGlobalBounds().width / 2) - _mainMenu.getGlobalBounds().width/1.5, (this->_mainMenu.getGlobalBounds().height * 6));
		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2) + _playButton.getGlobalBounds().width/1.5, (this->_playButton.getGlobalBounds().height * 6));



		soundBufferLose.loadFromFile(SOUND_LOSE);
		soundLose.setBuffer(soundBufferLose);
		soundLose.setVolume(50.f);
		soundLose.play();
	}
	void LoseScreenState::HandleInput()
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
			if (this->_data->input.IsSpriteClicked(this->_playButton, Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new ChooseLevelState(_data)), true);
			}

		}
	}

	void LoseScreenState::Update(double dt)
	{

	}

	void LoseScreenState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_gameOver);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_mainMenu);
		this->_data->window.display();
	}
}
