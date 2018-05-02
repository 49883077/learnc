#include "TreeNode.h"

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int size = nums.size();
		if (size == 0){
			return NULL;
		}
		else if (size == 1)
		{
			return new TreeNode(nums[0]);
		}
		
		int middle = size / 2;
		TreeNode *root = new TreeNode(nums[middle]);
		
		vector<int> leftVec(nums.begin(), nums.begin() + middle);
		vector<int> rightVec(nums.begin() + middle + 1, nums.end());

		root->left = sortedArrayToBST(leftVec);
		root->right = sortedArrayToBST(rightVec);

		return root;
	}
};


void main108()
{
	

	system("pause");
}