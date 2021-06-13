#include "Game.h"
#include "SplashState.h"
using namespace std;
using namespace sf;

namespace BreakOut
{
	Game::Game(int width, int height, string title)
	{
		_data->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));


		this->Run();

	}

	void Game::Run()
	{
		double newTime, frameTime, interpolation;
		double currentTime = this->_clock.getElapsedTime().asSeconds();
		double accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChange();
			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;
			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}
			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);
				accumulator -= dt;

			}
			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);

		}
	}
}
