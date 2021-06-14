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
	
	Paletka::Paletka(double X, double Y)
	{
		ksztalt.setPosition(X, Y);
		ksztalt.setSize({ SzerPaletka,WysPaletka });
		ksztalt.setFillColor(Color::Green);
		ksztalt.setOrigin(SzerPaletka / 2.f, WysPaletka / 2.f);

	}


	void GameState::Init()
	{

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->Draw();

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
		this->ksztalt.move(this->Szyb);
		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->prawa() < SCREEN_WIDTH || Keyboard::isKeyPressed(Keyboard::Key::D) && this->prawa() < SCREEN_WIDTH)
		{
			Szyb.x = SzybPaletka;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->lewa() > 0 || Keyboard::isKeyPressed(Keyboard::Key::A) && this->lewa() > 0)
		{
			Szyb.x = -SzybPaletka;
		}
		else
		{
			Szyb.x = 0;
		}
	}

	



	void GameState::Draw(double dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.display();
		target.draw(this->ksztalt, state);

	}

	void GameState::draw(RenderTarget& target, RenderStates state)const
	{
		target.draw(this->ksztalt, state);
	}

	double Paletka::prawa()
	{
		return this->ksztalt.getPosition().x + ksztalt.getSize().x / 2.f;
	}

	double Paletka::lewa()
	{
		return this->ksztalt.getPosition().x - ksztalt.getSize().x / 2.f;
	}

	double Paletka::gora()
	{
		return this->ksztalt.getPosition().y - ksztalt.getSize().y / 2.f;
	}

	double Paletka::dol()
	{
		return this->ksztalt.getPosition().y + ksztalt.getSize().y / 2.f;
	}

	Vector2f Paletka::getPosition()
	{
		return ksztalt.getPosition();
	}
}


