/*
24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
 */

#include "iostream"
#include "vector"
#include "string"
#include "stack"

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* swapPairs(ListNode* head)
{
    ListNode* pHead = new ListNode(-1);
    ListNode* l0 = pHead;
    pHead->next = head;
    while(l0->next != NULL && l0->next->next != NULL)
    {
        ListNode* l1 = l0->next;
        ListNode* l2 = l0->next->next;
        l0->next = l2;
        l1->next = l2->next;
        l2->next = l1;

        l0 = l1;
    }

    return pHead->next;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);

    ListNode* l2 = new ListNode(3);
    // l2->next = new ListNode(4);
    l1->next->next = l2;

    ListNode* l3 = swapPairs(l1);

    while(l3 != NULL)
    {
        cout << l3->val << endl;
        l3 = l3->next;
    }

    // delete l1->next->next;
    // delete l1->next;
    // delete l1;
    //
    // delete l2->next->next->next;
    // delete l2->next->next;
    // delete l2->next;
    // delete l2;

    // delete l3;

	return 0;
}
