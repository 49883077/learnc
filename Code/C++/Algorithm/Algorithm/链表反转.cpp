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


ListNode* reverse2(ListNode* head){

	ListNode* p;
	ListNode* q;
	ListNode* r;

	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	else
	{
		p = head;
		q = head->next;
		head->next = NULL;
		while (q)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		head = p;	
	}
	return head;
}


ListNode* reverse3(ListNode* head){
	
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while (curr != nullptr)
	{
		ListNode* nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	return prev;
}

void main1003()
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
	reverse3(list1);
	system("pause");
}