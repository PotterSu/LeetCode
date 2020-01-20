/*
输入一个链表，反转链表后，输出新链表的表头。
*/

#include "iostream"

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

//NULL 1 2 3 4
ListNode* ReverseList(ListNode* pHead)
{
    if(pHead == NULL || pHead->next == NULL)
        return pHead;
    ListNode* pPre = NULL;
    ListNode* head = pHead;
    ListNode* pNext = pHead->next;
    while(pNext !=NULL)
    {
        head->next = pPre;
        pPre = head;
        head = pNext;
        pNext = head->next;
    }
    head->next = pPre;

    return head;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
	ListNode* result = ReverseList(l1);
    while(result != NULL)
    {
        cout << result->val << endl;
        result = result->next;
    }

    delete l4;
    l4 = NULL;
    delete l3;
    l3 = NULL;
    delete l2;
    l2 = NULL;
    delete l1;
    l1 = NULL;

	return 0;
}
