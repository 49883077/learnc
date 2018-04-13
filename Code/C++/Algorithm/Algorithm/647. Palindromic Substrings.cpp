#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int len = s.size();
		int res = 0;
		vector<vector<bool>> dp(len, vector<bool>(len, false));
		for (int i = len - 1; i >= 0;i--)
		{
			for (int j = i; j < len; j++)
			{
				dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
				if (dp[i][j]) ++res;
			}
		}
		return res;
	}
};

struct Quad
{
	int u;
	int v;
	
};



void main647()
{
	Solution s;
	s.countSubstrings("abc");
	//Test 
	std::vector<Quad> _quads;

	for (int i = 0; i < 10; i++)
	{
		Quad quad = { 1, 1 };
		_quads.push_back(quad);
	}

	auto quad2 = &_quads[0];

	std::cout << &_quads[0];

	system("pause");
}