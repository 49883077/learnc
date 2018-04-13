#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int temp = k % nums.size();
		myReverse(nums, 0, nums.size() - temp -1);
		myReverse(nums, nums.size() -temp, nums.size() - 1);
		myReverse(nums, 0, nums.size() - 1);
		
	}

	void myReverse(vector<int>& nums, int left, int right)
	{
		while (left < right)
		{
			int temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
			right--;
		}
	}
	

};

void mainRotation()
{
	vector<int> nums = { 1, 2 };
	Solution* solution = new Solution();
	solution->rotate(nums, 0);
	cout << nums.size();
	system("pause");
}