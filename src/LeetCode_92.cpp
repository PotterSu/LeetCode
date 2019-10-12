/*
92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

解题思路：1 - 2 - 3 - 4 - 5 m=2 n =4
          也就是说我们要调换2 3 4
		  那么首先调换3与2，让1 - 3 - 2 - 4 - 5
		  再调换4与3，让1 - 4 - 3 - 2 - 5
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		int i = 0;
		ListNode *listhead = new ListNode(-1);
		listhead->next = head;//-1 3 5
		ListNode *afterhead = listhead;
		while (i<m - 1)//m = 1 n =2
		{
			if (afterhead->next != NULL)
				afterhead = afterhead->next;
			i++;
		}
		ListNode *start = afterhead->next;
		ListNode *then = start->next;
		for (int j = m; j<n; j++)
		{
			start->next = then->next;
			then->next = afterhead->next;
			afterhead->next = then;
			then = start->next;
		}
		return listhead->next;
	}
};

