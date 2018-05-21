#include "TreeNode.h"
void Swap(vector<int> &nums, int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void bubbleSort(vector<int> &nums)
{
	int size = nums.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i;j++)
		{
			if (nums[j]>nums[j+1])
			{
				Swap(nums, j, j + 1);
			}
		}
	}


}

void mainsorty()
{
	vector<int> nums = { 6, 5, 3, 1, 8, 7, 2, 4 };
	bubbleSort(nums);

	for (size_t i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
	}

	system("pause");
}

