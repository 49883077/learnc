#include "TreeNode.h"
class Solution {
public:
	int maxProfit122(vector<int>& prices) {
		int ret = 0;
		for (size_t p = 1; p < prices.size(); ++p)
			ret += max(prices[p] - prices[p - 1], 0);
		return ret;
	}
};

void main122()
{
	vector<int> nums = { 7, 1, 5, 3, 6, 4 };
	Solution s;
	s.maxProfit122(nums);
}                  