#include "Brick.h"
#include"Definitions.h"
#include"Levels.h"
#include <iostream>
#include"MainMenuState.h"
using namespace sf;

namespace BreakOut
{

	Brick::Brick(GameDataRef data) : _data( data )
	{
		_data->assets.LoadTexture("Brick", BRICK_FILEPATH);
	}
	void Brick::SpawnBrick(double width, double height )
	{
		
		Sprite sprite(_data->assets.GetTexture("Brick"));
		//cout << sprite.getTexture()->getSize().x << endl;
		float x = (float)(SCREEN_WIDTH / AMOUNT_OF_BRICK_IN_LINE) / (float)(sprite.getTexture()->getSize().x + 11);
		sprite.setScale(x,x);
		sprite.setPosition((sprite.getGlobalBounds().width)*width + 5 + 4*width, (sprite.getGlobalBounds().height)*height + 4 * height);
		brickSprites.push_back(sprite);
	}

	void Brick::DeleteBrick(Sprite sprite, int i) {
		brickSprites.erase(brickSprites.begin() + i);
		sprite.setPosition(-1000, 0);
		//cout << "Brick " << i << endl;
	}

	void Brick::DrawBricks()
	{
		for (int i = 0; i < brickSprites.size(); i++)
		{
			_data->window.draw(brickSprites.at(i));
		}
		
	}

	void Brick::PrepareLevel(int level) {
		Levels levels;
		/*cout << levels.level.size();*/
		try {
			if (level >= levels.level.size()) {
				throw;
			}
			for (int i = 0; i < levels.level[level].size(); i++) {
				SpawnBrick(levels.level[level].at(i)[0], levels.level[level].at(i)[1]);
			}
		}
		catch (exception e) {
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	const vector<Sprite> &Brick::GetSprites() const {
		return brickSprites;
	}
}
