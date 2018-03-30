#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double result = 0.0;
		vector<int> newNumbers;
		int i = 0;
		int j = 0;
		if (nums1.empty() && nums2.empty())
		{
			return NULL;
		}
		else if (nums1.empty())
		{
			newNumbers = nums2;
		}
		else if (nums2.empty())
		{
			newNumbers = nums1;
		}
		else
		{
			while (true)
			{
				if (nums1[i] > nums2[j])
				{
					newNumbers.push_back(nums2[j]);
					j++;
				}
				else{
					newNumbers.push_back(nums1[i]);
					i++;
				}
				if (i >= nums1.size() || j >= nums2.size())
					break;
			}


			for (i = i; i < nums1.size(); i++)
			{
				newNumbers.push_back(nums1[i]);
			}

			for (j = j; j < nums2.size(); j++)
			{
				newNumbers.push_back(nums2[j]);
			}
		}

		if (newNumbers.size() % 2 == 0)
		{
			int index = (newNumbers.size()) / 2;
			result = (newNumbers[index-1] + newNumbers[index]) / 2.0;
		}
		else
		{
			int index = (newNumbers.size()) / 2.0 ;
			result = newNumbers[index];
		}
		return result;
	}
};

int main004()
{
	vector<int> nums1 = {1,2 };
	vector<int> nums2 = {3,4 };
	Solution *solution = new Solution();
	double result = solution->findMedianSortedArrays(nums1, nums2);
	
	cout << result;
	getchar();
	return 1;
}

