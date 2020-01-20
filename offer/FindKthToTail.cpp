/*
输入一个链表，输出该链表中倒数第k个结点。
*/

#include "iostream"

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == NULL)
        return NULL;
    ListNode* pHead = pListHead;
    int length = 0;
    while(pHead != NULL)
    {
        length++;
        pHead = pHead->next;
    }
    if(k > length)
        return pHead;
    pHead = pListHead;
    for(int i = 0; i < length - k; i++)
    {
        pHead = pHead->next;
    }
    return pHead;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);

    l1->next = l2;
    l2->next = l3;
	ListNode* result = FindKthToTail(l1, 3);
    cout << result->val << endl;

    delete l3;
    l3 = NULL;
    delete l2;
    l2 = NULL;
    delete l1;
    l1 = NULL;

	return 0;
}
