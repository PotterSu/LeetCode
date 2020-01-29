/*
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(pHead == NULL)
        return NULL;
    ListNode* pSlow = pHead;
    ListNode* pFast = pHead;
    bool flag = false;
    while(pFast && pFast->next)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if(pSlow == pFast)
        {
            flag = true;
            break;
        }
    }
    if(!flag)
        return NULL;
    else
    {
        //计算环节点数
        int n = 1;
        pFast = pFast->next;
        while(pSlow != pFast)
        {
            pFast = pFast->next;
            n++;
        }
        //让两者相差n
        pSlow = pHead;
        pFast = pHead;
        for(int i = 0; i < n; i++)
        {
            pFast = pFast->next;
        }
        while(pSlow != pFast)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pSlow;
    }
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
    l3->next = l4;
    l4->next = l5;
    l5->next = l3;
	ListNode* result = EntryNodeOfLoop(l1);
    if(result != NULL)
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
