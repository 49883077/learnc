#include "TreeNode.h"

ListNode* reverse(ListNode* list){
	ListNode* head = new ListNode(0);
	bool isFirst = true; 
	while (list)
	{
		if (head->next)
		{
			ListNode* temp = head->next;
			if (isFirst)//也可以拿一个指针直接记录
			{
				temp->next = NULL;
				isFirst = false;
			}
			//
			head->next = list;
			list = list->next;
			head->next->next = temp;
		}
		else
		{
			head->next = list;
			list = list->next;
		}
	}
	
	return head->next;
}



void main_110086()
{
	ListNode* list5 = new ListNode(5);
	ListNode* list4 = new ListNode(4);
	ListNode* list3 = new ListNode(3);
	ListNode* list2 = new ListNode(2);
	ListNode* list1 = new ListNode(1);
	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = list5;
	list5->next = NULL;
	reverse(list1);
	system("pause");
}