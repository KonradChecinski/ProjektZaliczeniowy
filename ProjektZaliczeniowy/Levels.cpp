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
		
			for (int i = 0; i < 2*AMOUNT_OF_BRICK_IN_LINE-2; i+=2) {
				level4.push_back({(float)(i*0.5+0.5), 0});

			}
			level4.push_back({ 1,1 });
			level4.push_back({ 2,1 });
			level4.push_back({ 3,1 });
			level4.push_back({ 4,1 });
			level4.push_back({ 5,1 });
			level4.push_back({ 6,1 });
			level4.push_back({ 7,1 });
			level4.push_back({ 8,1 });
			level4.push_back({ 9,1 });
			level4.push_back({ 10,1 });
			level4.push_back({ 11,1 });
			level4.push_back({ 12,1 });
			level4.push_back({ 13,1 });

			level4.push_back({ 1.5,2 });
			level4.push_back({ 2.5,2 });
			level4.push_back({ 3.5,2 });
			level4.push_back({ 5.5,2 });
			level4.push_back({ 6.5,2 });
			level4.push_back({ 7.5,2 });
			level4.push_back({ 8.5,2 });
			level4.push_back({ 10.5,2 });
			level4.push_back({ 11.5,2 });
			level4.push_back({ 12.5,2 });

			level4.push_back({ 2,3 });
			level4.push_back({ 3,3 });

			level4.push_back({ 6,3 });
			level4.push_back({ 7,3 });
			level4.push_back({ 8,3 });
			level4.push_back({ 11,3 });
			level4.push_back({ 12,3 });
			 
			level4.push_back({ 2.5,4 });
			level4.push_back({ 6.5,4 });
			level4.push_back({ 7.5,4 });
			level4.push_back({ 11.5,4 });

			level4.push_back({ 7,5 });


		level.push_back(level4);
		


		

	}
}