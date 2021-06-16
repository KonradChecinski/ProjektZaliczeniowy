#pragma once

#include<vector>
#include<array>
using namespace std;

namespace BreakOut
{
	class Levels
	{
	public:
		Levels();
		vector<array<float, 2>> level1;
		array<float, 2> brick;
		vector<vector<array<float, 2>>> level;
		
		
	};

}