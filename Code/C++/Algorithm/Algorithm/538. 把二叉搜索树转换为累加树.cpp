#include "TreeNode.h"

/*

*/

class Solution {
public:
	//递归实现
	int sum = 0;

	TreeNode* travel(TreeNode* root){
		if (!root){
			return NULL;
		}
		if (root->right){
			travel(root->right);
		}

		root->val = (sum += root->val);

		if (root->left){
			travel(root->left);
		}
	}

	//栈实现
	vector<int> travelByStack(TreeNode* root){
		stack<TreeNode*> nodeStack;
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}
		nodeStack.push(root);
		while (!nodeStack.empty()){

			TreeNode* temp = nodeStack.top();
			result.push_back(temp->val);
			nodeStack.pop();
			if (temp->right)
			{
				TreeNode* right = temp->right;
				nodeStack.push(right);
			}
			
			if (temp->left)
			{
				TreeNode* left = temp->left;
				nodeStack.push(left);
			}
		}
		return result;
	}

	TreeNode* convertBST(TreeNode* root) {
		//travel(root);
		int sum = 0;
		TreeNode* head = root;
		stack<TreeNode*> stackNode;
		while (root != NULL || !stackNode.empty())
		{
			if (root != NULL)
			{
				stackNode.push(root);
				root = root->right;
			}
			else{
				TreeNode* tempNode = stackNode.top();
				tempNode->val = (sum += tempNode->val);
				stackNode.pop();
				root = tempNode->left;
			}
		}
		return head;
	}
};

void main538()
{
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(13);
	TreeNode* root = new TreeNode(5);
	root->left = left;
	root->right = right;

	Solution s;
	s.convertBST(root);
}
