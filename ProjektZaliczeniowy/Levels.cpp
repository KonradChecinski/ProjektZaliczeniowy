#include "Levels.h"
#include "Definitions.h"
#include<vector>
#include<iostream>

using namespace std;
namespace BreakOut
{
	Levels::Levels() {
		vector<array<float, 2>> level1{};
		array<float, 2> brick{};

		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < AMOUNT_OF_BRICK_IN_LINE; i++) {
				brick = { (float)i,(float)j };
				level1.push_back(brick);
			}
		}
		


		level.push_back(level1);
		
	}
}