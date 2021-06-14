#pragma once
#include<SFML/Graphics.hpp>
#include"Game.h"
#include"State.h"
#include "Definitions.h"
using namespace sf;

namespace BreakOut
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);
		
		GameState(double X, double Y);
		GameState() = delete;
		~GameState() = default;


		Vector2f getPosition();


		double prawa();
		double lewa();
		double gora();
		double dol();

		void Init();
		void HandleInput();
		void Update(double dt);
		void Draw(double dt);

	private:


		GameDataRef _data;
		Sprite _background;
		void Draw(double dt);
		RectangleShape ksztalt;
		Vector2f Szyb{ SzybPaletka,0.f };
	};
	
	

}