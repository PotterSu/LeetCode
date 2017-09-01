/*
92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

解题思路：设置三个定位变量分别为i,j,index，用来定位nums1，nums2，nums1合并后的位置
          从nums1，nums2的最后向前遍历，大的值存到nums1的index的位置，index--
		  将剩下的nums1或nums2的元素直接赋值给nums1前面的空位
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

