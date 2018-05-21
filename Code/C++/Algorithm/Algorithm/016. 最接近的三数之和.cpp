#include "TreeNode.h"

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size();
		int ret = 0;
		int originSize = size;
		if (size <= 3)
		{
			for (int i = 0; i < size; i++)
			{
				ret += nums[i];
			}
			return ret;
		}

		int mindiff = 0;
		sort(nums.begin(), nums.end());
		size -= 2;
			
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			int left = i + 1;
			int right = originSize - 1;
			while (left < right)
			{
				sum = nums[i] + nums[left] + nums[right];
				if (sum > target)
				{
					right--;
				}
				else if (sum < target)
				{
					left++;
				}
				else{
					return sum;
				}

				int dis = abs(target - sum);
				if (mindiff == 0 || dis < mindiff)
				{
					mindiff = dis;
					ret = sum;
				}
			}
		}
		return ret;
	}
};
