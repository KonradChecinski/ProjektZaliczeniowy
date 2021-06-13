#include "AssetManager.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;


namespace BreakOut
{
	void AssetManager::LoadTexture(string name, string fileName)
	{
		Texture texture;
		
		if (texture.loadFromFile(fileName))
		{
			this->_textures[name] = texture;
		}
	}
	Texture& AssetManager::GetTexture(string name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(string name, string fileName)
	{
		Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}
	Font& AssetManager::GetFont(string name)
	{
		return this->_fonts.at(name);
	}
}

