/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

#include "iostream"

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

//-1 1 3 5 7
//2 3 6 8
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    if(pHead2 == NULL)
        return pHead1;
    ListNode* l1 = pHead1;
    ListNode* l2 = pHead2;
    ListNode* pHead = new ListNode(-1);
    ListNode* pTemp = pHead;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val)
        {
            pTemp->next = l1;
            l1 = l1->next;
            pTemp = pTemp->next;
        }
        else
        {
            pTemp->next = l2;
            l2 = l2->next;
            pTemp = pTemp->next;
        }
    }
    while(l1 != NULL)
    {
        pTemp->next = l1;
        l1 = l1->next;
        pTemp = pTemp->next;
    }
    while(l2 != NULL)
    {
        pTemp->next = l2;
        l2 = l2->next;
        pTemp = pTemp->next;
    }
    pTemp = pHead->next;
    delete pHead;
    pHead = NULL;
    return pTemp;
}

int main()
{
    ListNode* l11 = new ListNode(1);
    ListNode* l12 = new ListNode(3);
    ListNode* l13 = new ListNode(5);
    ListNode* l14 = new ListNode(7);

    ListNode* l21 = new ListNode(2);
    ListNode* l22 = new ListNode(3);
    ListNode* l23 = new ListNode(6);
    ListNode* l24 = new ListNode(8);

    l11->next = l12;
    l12->next = l13;
    l13->next = l14;

    l21->next = l22;
    l22->next = l23;
    l23->next = l24;
	ListNode* result = Merge(l11, l21);
    while(result != NULL)
    {
        cout << result->val << endl;
        result = result->next;
    }

    delete l14;
    l14 = NULL;
    delete l13;
    l13 = NULL;
    delete l12;
    l12 = NULL;
    delete l11;
    l11 = NULL;

    delete l24;
    l24 = NULL;
    delete l23;
    l23 = NULL;
    delete l22;
    l22 = NULL;
    delete l21;
    l21 = NULL;

	return 0;
}
