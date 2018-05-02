#include "TreeNode.h"
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxCur = 0;
		int maxSoFar = 0;
		for (int i = 1; i < prices.size();i++)
		{
			maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
			maxSoFar = max(maxCur, maxSoFar);
		}
		return maxSoFar;
	}
};

void main121()
{
	vector<int> nums = { 7, 1, 5, 3, 6, 4 };
	Solution s;
	s.maxProfit(nums);
}