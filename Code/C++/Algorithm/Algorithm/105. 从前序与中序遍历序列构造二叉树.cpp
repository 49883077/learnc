#include "TreeNode.h"

class Solution {
public:
	//前序 中序 
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode* root = buildTree(0, preorder.size() - 1, 0, inorder.size() - 1,preorder, inorder);
		return root;
	}

	TreeNode* buildTree(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
		if (preStart > preEnd || inStart > inEnd){
			return NULL;
		}
		int rootVal = preorder[preStart];
		int index = 0;
		for (index = inStart; index <= inEnd; index++){
			if (rootVal == inorder[index]){
				break;
			}
		}

		TreeNode* root = new TreeNode(rootVal);
		root->left = buildTree(preStart + 1, preStart + (index - inStart), inStart, index - 1, preorder, inorder);
		root->right = buildTree(preStart + 1 + (index - inStart), preEnd, index + 1, inEnd, preorder, inorder);
		return root;
	}

	//中序 后序
	TreeNode* buildTree22(vector<int>& inorder, vector<int>& postorder) {
		TreeNode* root = buildTree22(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
		return root;
	}

	TreeNode* buildTree22(int inStart, int inEnd, int postStart, int postEnd, vector<int>& inorder, vector<int>& postorder){
		if (postStart > postEnd || inStart > inEnd){
			return NULL;
		}

		int rootVal = postorder[postEnd]; //root节点
		int index = 0;
		for (index; index <= inEnd; index++)
		{
			if (rootVal == inorder[index])
			{
				break;
			}
		}
		TreeNode* root = new TreeNode(rootVal);
		//(index - 1 - inStart)  inorder leftChild number  
		//根据root在inorder的位置，求出左右两边的元素个数
		root->left = buildTree22(inStart, index - 1,  postStart, postStart + (index - 1 - inStart), inorder, postorder);
		root->right = buildTree22(index + 1, inEnd, postEnd - 1 - (inEnd - index - 1), postEnd - 1, inorder, postorder);
		return root;
	}


};


void main105()
{
	vector<int> preorder = { 3, 9, 20, 15, 7 };
	vector<int> inorder = { 9, 3, 15, 20, 7 };
	Solution S;
	S.buildTree(preorder,inorder);
	system("pause");
}