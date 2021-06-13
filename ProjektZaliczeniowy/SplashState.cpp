#include "SplashState.h"
#include <sstream>
#include<iostream>
#include"Definitions.h"
#include"MainMenuState.h"
using namespace sf;
using namespace std;

namespace BreakOut
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}
	void SplashState::Init()
	{
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
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
	void SplashState::Update(double dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > 1.5)
		{
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);		
		}
	}

	void SplashState::Draw(double dt)
	{
		this->_data->window.clear(Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.display();

	}
}
