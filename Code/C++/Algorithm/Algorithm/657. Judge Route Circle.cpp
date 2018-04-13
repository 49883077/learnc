#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	bool judgeCircle(string moves) {
		int x = 0;
		int y = 0;
		for (auto str : moves)
		{
			switch (str)
			{
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;

			case 'L':
				x--;
				break;

			case 'R':
				x++;
				break;

			}
		}
		if (x == 0 && y == 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
};