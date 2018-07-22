/*
2.
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

解题思路：首先创建l3结果链表头节点，后续加的结果直接加到l3尾部，再用pNode4指向l3头节点便于返回整个结果链表
          接下来对l1和l2公共部分进行加和，注意进位问题
          然后对l1或者l2多出的部分单独进行加和
		  最后判断最后一次加和是否有进位，有进位还需要再创建个节点
		  返回pNode4即可
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int l1_length = 0;
		int l2_length = 0;
		ListNode *pNode1 = l1;
		ListNode *pNode2 = l2;
		//创建返回结果链表的头结点
		ListNode *l3 = new ListNode(-1);
		//指向头节点便于返回整个链表
		ListNode *pNode4 = l3;
		int temp = 0;
		while (pNode1 != NULL && pNode2 != NULL)
		{
			ListNode *pNode3 = new ListNode((temp + pNode1->val + pNode2->val) % 10);
			temp = (temp + pNode1->val + pNode2->val) / 10;
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
			l3->next = pNode3;
			l3 = l3->next;
		}
		while (pNode1 != NULL)
		{
			ListNode *pNode3 = new ListNode((temp + pNode1->val) % 10);
			temp = (temp + pNode1->val) / 10;
			pNode1 = pNode1->next;
			l3->next = pNode3;
			l3 = l3->next;
		}
		while (pNode2 != NULL)
		{
			ListNode *pNode3 = new ListNode((temp + pNode2->val) % 10);
			temp = (temp + pNode2->val) / 10;
			pNode2 = pNode2->next;
			l3->next = pNode3;
			l3 = l3->next;
		}
		if (temp != 0)
		{
			ListNode *pNode3 = new ListNode(temp);
			l3->next = pNode3;
			l3 = l3->next;
		}
		return pNode4->next;
	}
};
int main()
{
	Solution* solution = new Solution();
	ListNode *l1 = new ListNode(9);
	ListNode *l12 = new ListNode(9);
	ListNode *l13 = new ListNode(9);
	l1->next = l12;
	l12->next = l13;
	ListNode *l2 = new ListNode(9);
	ListNode *l22 = new ListNode(9);
	ListNode *l23 = new ListNode(9);
	l2->next = l22;
	l22->next = l23;
	ListNode *l3 = solution->addTwoNumbers(l1, l2);
	while (l3 != NULL)
	{
		std::cout << l3->val << std::endl;
		l3 = l3->next;
	}

	delete(solution);
	delete(l1);
	delete(l2);
	delete(l22);
	delete(l23);
	delete(l3);
	return 0;
}