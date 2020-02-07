/*
输入两个链表，找出它们的第一个公共结点。
*/

#include "iostream"

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

int GetListLength(ListNode* pHead)
{
    int length = 0;
    ListNode* p = pHead;
    while(p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2)
{
    int length1 = GetListLength(pHead1);
    int length2 = GetListLength(pHead2);

    int diff = abs(length1 - length2);
    cout << diff << endl;

    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    for(int i = 0; i < diff; i++)
    {
        if(length1 >= length2)
        {
            p1 = p1->next;
        }
        else
        {
            p2 = p2->next;
        }
    }
    while(p1 != NULL && p2 != NULL)
    {
        if(p1 == p2)
            return p1;
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return p1;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);

    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);

    l1->next = l2;
    l2->next = l3;

    l4->next = l5;
    l5->next = l2;
	ListNode* result = FindFirstCommonNode(l1, l4);
    cout << result->val << endl;

    delete l5;
    l5 = NULL;
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
