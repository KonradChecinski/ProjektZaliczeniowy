#pragma once
#include<memory>
#include<string>
#include<SFML/Graphics.hpp>
#include"StateMachine.h"
#include"AssetManager.h"
#include"InputManager.h"

using namespace sf;
using namespace std;


namespace BreakOut
{
	
	struct GameData
	{
		StateMachine machine;
		RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef shared_ptr<GameData>GameDataRef;
	
	class Game
	{
	public:
		Game(int width, int height, string title);
	
	private:
		const double dt = 1.0f / 144.0f;
		Clock _clock;
		

		GameDataRef _data = make_shared<GameData>();

		void Run();


	};
}

