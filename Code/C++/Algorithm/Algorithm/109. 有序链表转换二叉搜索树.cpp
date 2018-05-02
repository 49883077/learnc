#include "TreeNode.h"
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		TreeNode* root = sortHead2TailBST(head, NULL);
		return root;
	}

	TreeNode* sortHead2TailBST(ListNode *head, ListNode *tail)
	{
		if (head == tail){
			return NULL;
		}
		if (head->next == tail){
			TreeNode* root = new TreeNode(head->val);
			return root;
		}

		ListNode *tempNode = head;
		ListNode *middleNode = head;
		while (tempNode != tail && tempNode->next != tail){ //Ѱ���м�ڵ� �ܹؼ�
			middleNode = middleNode->next;
			tempNode = tempNode->next->next;
		}

		TreeNode* root = new TreeNode(middleNode->val);
		root->left = sortHead2TailBST(head, middleNode);
		root->right = sortHead2TailBST(middleNode->next, tail);
		return root;
	}

};