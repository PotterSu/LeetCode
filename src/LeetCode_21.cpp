/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode l3 = ListNode(-1);
    ListNode* l3temp = &l3;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val)
        {
            l3temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            l3temp->next = l2;
            l2 = l2->next;
        }
        l3temp = l3temp->next;
    }

    l3temp->next = l1 != NULL ? l1 : l2;
    ListNode* rstNode = l3.next;
    return rstNode;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(5);

    ListNode* l3 = mergeTwoLists(l1, l2);

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
