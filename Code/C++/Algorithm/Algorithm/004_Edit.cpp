#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums2.size() > nums1.size())
		{
			swap(nums1, nums2);
		}

		int pos = nums1.size() / 2;
		for (int i = 0; i < nums2.size(); i++)
		{
			if (nums2[i] >= nums1[pos])
				pos++;
			else
				pos--;
			nums1.push_back(nums2[i]);
		}

		std::sort(nums1.begin(), nums1.end());
		int size = nums1.size();

		if (size % 2)
		{
			return nums1[size / 2];
		}
		else
		{
			return (double)(nums1[size / 2] + nums1[size / 2 - 1]) / 2;
		}
	}
};

int main0042()
{
	vector<int> nums1 = { 1, 3 };
	vector<int> nums2 = { 2 };
	Solution *solution = new Solution();
	double result = solution->findMedianSortedArrays(nums1, nums2);

	cout << result;
	getchar();
	return 0;
}

