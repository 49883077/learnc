#include "TreeNode.h"

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		int size = nums.size();
		if (size < 4)
		{
			return res;
		}
		if (nums[size - 1] + nums[size - 2] + nums[size - 3] + nums[size - 4] < target)
		{
			return res;
		}

		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < size; i++)
		{

		}
	}
};