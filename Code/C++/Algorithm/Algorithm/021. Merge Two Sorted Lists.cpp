
// Definition for singly-linked list.
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
		ListNode dummy(0);
		ListNode *tail = &dummy;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				tail->next = l2;
				l2 = l2->next;
			}
			else
			{
				tail->next = l1;
				l1 = l1->next;
			}
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
};

void main021()
{
	ListNode* node3 = new ListNode(3);
	node3->next = NULL;
	ListNode* node1 = new ListNode(1);
	node1->next = node3;


	ListNode* node4 = new ListNode(4);
	node4->next = NULL;
	ListNode* node2 = new ListNode(2);
	node2->next = node4;

	Solution solu;
	solu.mergeTwoLists(node1, node2);

	system("pause");
}