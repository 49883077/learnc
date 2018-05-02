#include "TreeNode.h"
class Solution {
public:
	//³¬Ê±
	void flatten(TreeNode* root) {
		TreeNode* head = new TreeNode(1);
		TreeNode* head_res = head;
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
				//head->right = root;
				//cout << root->val << endl;
				head->right = root;
				head = head->right;
				stackNode.pop();
				root = root->right;
			}

		}
		root = head_res->right;
	}

	//
	 TreeNode *prev = NULL;
	 void flatten2(TreeNode* root) {
		if (root == NULL)
			return;
		flatten2(root->right);
		flatten2(root->left);
		root->right = prev;
		root->left =NULL;
		prev = root;
	}


};

void main114()
{
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(13);
	TreeNode* right_right = new TreeNode(16);
	TreeNode* root = new TreeNode(5);
	root->left = left;
	root->right = right;
	right->right = right_right;
	Solution s;
	s.flatten2(root);
}
