/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

#include "iostream"
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};
// -1 1 2 2 3
ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead == NULL || pHead->next == NULL)
        return pHead;
    ListNode* pFirst = new ListNode(-1);
    pFirst->next = pHead;
    ListNode* pPre = pFirst;
    ListNode* head = pHead;
    ListNode* pNext = head->next;
    int flag = 0;
    while(pNext != NULL)
    {
        if(head->val == pNext->val)
        {
            pNext = pNext->next;
            head->next = pNext;
            flag = 1;
        }
        else
        {
            //有重复的
            if(flag == 1)
            {
                pPre->next = pNext;
                head = pNext;
                pNext = pNext->next;
                flag = 0;
            }
            else
            {
                pPre = head;
                head = pNext;
                pNext = pNext->next;
            }
        }
    }
    if(flag == 1)
    {
        pPre->next = pNext;
    }

    return pFirst->next;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(3);
    ListNode* l5 = new ListNode(4);
    ListNode* l6 = new ListNode(4);
    ListNode* l7 = new ListNode(5);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
	ListNode* result = deleteDuplication(l1);
    while(result != NULL)
    {
        cout << result->val << endl;
        result = result->next;
    }

    delete l7;
    l7 = NULL;
    delete l6;
    l6 = NULL;
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
