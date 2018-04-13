#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int maxArea = 0;
		while (left < right)
		{
			int minHeight = min(height[left], height[right]);
			maxArea = max(maxArea, minHeight * (right - left));
			if (height[left] < height[right])
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		return maxArea;

	}
};



void main011()
{
	//isPalindrome(12521);
	Solution solution;
	vector<int> height{ 1, 1 };
	solution.maxArea(height);
	system("pause");
}