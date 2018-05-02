#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector <vector <int>> result;
		if (root == NULL)
		{
			return result;
		}
		queue<TreeNode*> _queue;
		_queue.push(root);
		while (!_queue.empty())
		{
			vector <int> temp;
			int _queueSize = _queue.size();
			for (int i = 0; i < _queueSize; i++)
			{
				TreeNode* frontNode = _queue.front();
				temp.push_back(frontNode->val);
				if (frontNode->left)
				{
					_queue.push(frontNode->left);
				}
				if (frontNode->right)
				{
					_queue.push(frontNode->right);
				}
				_queue.pop();
			}
			result.push_back(temp);
		}
		vector <vector <int>> newResult(result.rbegin(), result.rend());
		return newResult;
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector <vector <int>> paths;
		vector<int> temp;

		findPath(root, paths, temp, sum);
		return paths;

	}
	void findPath(TreeNode* root, vector <vector <int>> &paths, vector<int> temp, int sum)
	{
		if (root == NULL)
		{
			return;
		}
		temp.push_back(root->val);
		if (root->left == NULL && root->right == NULL && root->val == sum)
		{
			paths.push_back(temp);
		}
		if (root->left)
		{
			findPath(root->left, paths, temp, sum - root->val);
		}
		if (root->right)
		{
			findPath(root->right, paths, temp, sum - root->val);
		}
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> paths;
		string tempPath;
		findPath(root, paths,tempPath);
		return paths;
	}

	void findPath(TreeNode* root, vector<string> &paths, string tempPath)
	{
		if (root == NULL)
		{
			return;
		}
		if (!tempPath.empty())
			tempPath.append("->"); 
		//string tempStr;
		string tempStr = to_string(root->val);
		tempPath.append(tempStr);

		if (root->left == NULL && root->right == NULL)
		{
			paths.push_back(tempPath);
		}

		if (root->left)
		{
			findPath(root->left, paths, tempPath);
		}
		if (root->right)
		{
			findPath(root->right, paths, tempPath);
		}
	}

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector <vector <int>> result;
		if (root == NULL)
		{
			return result;
		}
		queue<TreeNode*> _queue;
		_queue.push(root);
		bool isFlip = false;
		while (!_queue.empty())
		{
			vector <int> temp;
			int _queueSize = _queue.size();
			for (int i = 0; i < _queueSize; i++)
			{
				TreeNode* frontNode = _queue.front();
				temp.push_back(frontNode->val);
				if (frontNode->left)
				{
					_queue.push(frontNode->left);
				}
				if (frontNode->right)
				{
					_queue.push(frontNode->right);
				}
				_queue.pop();
			}
			if (isFlip)
			{
				vector<int> temp2(temp.rbegin(), temp.rend());
				result.push_back(temp2);
			}
			else
			{
				result.push_back(temp);
			}
			isFlip = ~isFlip;
		}

	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return NULL;
		}
	}
};


void main102()
{
	/*TreeNode* node5 = new TreeNode(5);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node1 = new TreeNode(1);
	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node3->left = node5;

	Solution s;
	vector<string> paths = s.binaryTreePaths(node1);
	for (auto path : paths)
	{
		cout << path.c_str() << endl;
	}*/




	system("pause");
}