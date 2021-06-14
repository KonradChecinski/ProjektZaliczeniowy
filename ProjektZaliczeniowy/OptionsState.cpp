#include "OptionsState.h"
#include<sstream>
#include "Definitions.h"
#include<iostream>
#include"MainMenuState.h"
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

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_back.setTexture(this->_data->assets.GetTexture("Back"));
		this->_options1.setTexture(this->_data->assets.GetTexture("Options_1"));
		this->_options2.setTexture(this->_data->assets.GetTexture("Options_2"));

		this->_options1.setPosition((SCREEN_WIDTH / 2) - (this->_options1.getGlobalBounds().width / 2), this->_options1.getGlobalBounds().height * 0.8);
		this->_options2.setPosition((SCREEN_WIDTH / 2) - (this->_options2.getGlobalBounds().width / 2), (this->_options2.getGlobalBounds().height * 2.2));
		this->_back.setPosition((SCREEN_WIDTH / 2) - (this->_back.getGlobalBounds().width / 2), (this->_back.getGlobalBounds().height * 6.4));
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
		this->_data->window.display();
	}
}
