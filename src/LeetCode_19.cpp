/*
19.删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
*/

#include "iostream"
#include "vector"
#include "stack"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// ListNode* removeNthFromEnd(ListNode* head, int n)
// {
// 	int nLength = 0;
// 	ListNode* pHead = new ListNode(-1);
// 	pHead->next = head;
// 	ListNode* pHeadTemp = pHead;
// 	while(pHeadTemp != NULL)
// 	{
// 		nLength++;
// 		pHeadTemp = pHeadTemp->next;
// 	}
// 	pHeadTemp = pHead;
// 	for(int i = 0; i < nLength - n - 1; i++)
// 	{
// 		pHeadTemp = pHeadTemp->next;
// 	}
// 	pHeadTemp->next = pHeadTemp->next->next;
// 	return pHead->next;
// }

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode* pHead = new ListNode(-1);
	pHead->next = head;
	ListNode* pFore = pHead;
	ListNode* pBack = pHead;
	for(int i = 0; i < n; i++)
	{
		pBack = pBack->next;
	}
	while(pBack->next != NULL)
	{
		pFore = pFore->next;
		pBack = pBack->next;
	}
	pFore->next = pFore->next->next;
	return pHead->next;
}

int main()
{
	ListNode *l1 = new ListNode(1);
	ListNode *l12 = new ListNode(2);
	ListNode *l13 = new ListNode(3);
	l1->next = l12;
	l12->next = l13;

	ListNode *l3 = removeNthFromEnd(l1, 1);
	while (l3 != NULL)
	{
		std::cout << l3->val << std::endl;
		l3 = l3->next;
	}

	delete(l1);
	delete(l3);
	return 0;
}
