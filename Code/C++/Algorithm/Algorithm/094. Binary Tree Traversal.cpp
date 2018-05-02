#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;


 //Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> preOrderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}
		stack<TreeNode*> stackNode;
		stackNode.push(root);
		while (!stackNode.empty())
		{
			TreeNode* tempNode = stackNode.top();
			result.push_back(tempNode->val);
			stackNode.pop();
			if (tempNode->right != NULL)
			{
				stackNode.push(tempNode->right);
			}
			if (tempNode->left != NULL)
			{
				stackNode.push(tempNode->left);
			}
		}
	}

	vector<int> preOrderTraversal2(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stackNode;
		
		while (root != NULL || !stackNode.empty())
		{
			if (root != NULL)
			{
				result.push_back(root->val);
				stackNode.push(root);
				root = root->left;
			}
			else
			{
				root = stackNode.top();
				stackNode.pop();
				root = root->right;
			}
		}
	}


	vector<int> inOrderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stackNode;

		while (root != NULL || !stackNode.empty())
		{
			if (root != NULL)
			{
				stackNode.push(root);
				root = root->left;
			}
			else
			{
				root = stackNode.top();
				result.push_back(root->val);
				stackNode.pop();
				root = root->right;
			}
		}
		return result;
	}


	vector<int> postOrderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stackNode,outPutNode;
		stackNode.push(root);
		while (root != NULL || !stackNode.empty())
		{
			struct TreeNode* curr = stackNode.top();
			outPutNode.push(curr);
			stackNode.pop();
		}
		return result;
	}


	TreeNode* createTree(vector<int> nums)
	{

	}


};