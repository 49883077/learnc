#include "TreeNode.h"
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int ans = nums[0];
		for (int ii = 0; ii < nums.size(); ii++){
			if (sum<0)sum = 0;
			sum += nums[ii];
			ans = ans>sum ? ans : sum;
		}
		return ans;
	}
};

void main053()
{
	vector<int> nums = { 2, 4, -7, 5, 2, -1, 2, -4, 3 };
	Solution s;
	s.maxSubArray(nums);
}