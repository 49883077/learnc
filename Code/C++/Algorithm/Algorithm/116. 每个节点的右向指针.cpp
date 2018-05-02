#include "TreeNode.h"

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
		{
			return;
		}
		queue<TreeLinkNode*> _queue;
		_queue.push(root);
		while (!_queue.empty())
		{
			int size = _queue.size();
			TreeLinkNode* preNode = NULL;

			for (int i = 0; i < size; i++)
			{
				TreeLinkNode* _tempLinkNode = _queue.front();				
				if (i == (size - 1))
				{	
					_tempLinkNode->next = NULL;
				}
				
				if (preNode)
				{
					preNode->next = _tempLinkNode;
				}
				
				preNode = _tempLinkNode;
				if (_tempLinkNode->left)
				{
					_queue.push(_tempLinkNode->left);
				}
				if (_tempLinkNode->right)
				{
					_queue.push(_tempLinkNode->right);
				}
				_queue.pop();
			}
		}
	}
};

void main116()
{
	TreeLinkNode* left = new TreeLinkNode(2);
	TreeLinkNode* right = new TreeLinkNode(3);
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = left;
	root->right = right;
	Solution s;
	s.connect(root);

	while (root)
	{
		cout << root->val;
		root = root->next;

	}

}