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

		for (int j = 0; j < 7; j++)
		{
			for (int i = 0; i < AMOUNT_OF_BRICK_IN_LINE; i++) 
			{
				brick = { (float)i,(float)j };
				level1.push_back(brick);
			}
		}
		level.push_back(level1);

		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < AMOUNT_OF_BRICK_IN_LINE + j; i++)
			{
				brick = { (float)(i*2),(float)j };
				level2.push_back(brick);
			}
		}
		level.push_back(level2);


		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < AMOUNT_OF_BRICK_IN_LINE - j; i++)
			{
				brick = { (float)i+(float)(j*0.5),(float)j };
				level3.push_back(brick);
			}
		}
		level.push_back(level3);

		int k{};
		
			for (int j = 0; j < 12; j++)
			{


				for (int i = AMOUNT_OF_BRICK_IN_LINE - (6 - j); i <= AMOUNT_OF_BRICK_IN_LINE; i++)
				{
					brick = { (float)((AMOUNT_OF_BRICK_IN_LINE - (6 - j)) / 2.0) + (float)k - (float)0.5,(float)(j) };
					level4.push_back(brick);
					k++;
				}
				k = 0;

			}
		level.push_back(level4);
		


		

	}
}