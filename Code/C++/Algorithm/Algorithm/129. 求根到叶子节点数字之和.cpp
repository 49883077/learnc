/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include "TreeNode.h"

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		vector<vector<int>> res;
		vector<int> temp;
		if (root == NULL)
		{
			return 0;
		}
		
		findTreeLeaf(res, temp, root);
		
		int sum = 0;
		int row = res.size();
		for (int i = 0; i < row; i++)
		{
			int col = res[i].size();

			for (int j = 0; j < col; j++)
			{
				sum = sum + (res[i][j] * pow(10, col - j - 1));
			}
		}
		return sum;
	}

	void findTreeLeaf(vector<vector<int>> &res, vector<int> temp, TreeNode* root)
	{

		if (root)
		{
			temp.push_back(root->val);
		}
		else
		{
			return;
		}

		if (root->left == NULL && root->right == NULL)
		{
			res.push_back(temp);
		}

		if (root->left)
		{
			findTreeLeaf(res, temp, root->left);
		}

		if (root->right)
		{
			findTreeLeaf(res, temp, root->right);
		}
	}
};

void main129()
{
	TreeNode* left = new TreeNode(9);
	TreeNode* right = new TreeNode(0);
	TreeNode* root = new TreeNode(4);
	root->left = left;
	root->right = right;

	TreeNode* left_left = new TreeNode(5);
	TreeNode* left_right = new TreeNode(1);
	left->left = left_left;
	left->right = left_right;


	Solution s;
	s.sumNumbers(root);
}