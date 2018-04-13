#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0) return false;
	int div = 1;
	while (x / div >= 10) div *= 10;
	while (x > 0) {
		int left = x / div;
		int right = x % 10;
		if (left != right) return false;
		x = (x % div) / 10;
		div /= 100;
	}
	return true;
}




void main009()
{
	//isPalindrome(12521);
	string s ="Hello";

	string result = "";
	for (int i = s.size() - 1; i >= 0; i--)
	{
		result.push_back(s[i]);
	
	}


	system("pause");
}