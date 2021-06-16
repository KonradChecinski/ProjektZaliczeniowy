#include <SFML/Graphics.hpp>
#include<iostream>
#include "Game.h"
#include "Definitions.h"



int main()
{
	BreakOut::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "BreakOut");
	return EXIT_SUCCESS;
}