/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
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


ListNode* deleteDuplicates(ListNode* head)
{
    if(head == NULL)
        return head;
    ListNode* temp = head->next;
    ListNode* final = head;
    int first = head->val;
    while(temp != NULL)
    {
        if(temp->val != first)
        {
            final->next = temp;
            first = temp->val;
            temp = temp->next;
            final = final->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    final->next = NULL;
    return head;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(2);
    // l1->next->next->next = new ListNode(3);
    // l1->next->next->next->next = new ListNode(3);

    ListNode* l2 = deleteDuplicates(l1);

    while(l2 != NULL)
    {
        cout << l2->val << endl;
        l2 = l2->next;
    }

	return 0;
}
