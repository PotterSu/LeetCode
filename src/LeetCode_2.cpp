/*
2.两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

#include "iostream"
#include "string"
#include "algorithm"
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
		int temp = 0;
		ListNode* l3 = new ListNode(0);
		ListNode* pl3Head = l3;
		while(l1 != NULL && l2 != NULL)
		{
			l3->next = new ListNode((l1->val + l2->val + temp) % 10);
			temp = (l1->val + l2->val + temp) / 10;

			l3 = l3->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1 != NULL)
		{
			l3->next = new ListNode((l1->val + temp) % 10);
			temp = (l1->val + temp) / 10;
			l1 = l1->next;
			l3 = l3->next;
		}
		while(l2 != NULL)
		{
			l3->next = new ListNode((l2->val + temp) % 10);
			temp = (l2->val + temp) / 10;
			l2 = l2->next;
			l3 = l3->next;
		}
		if(temp != 0)
		{
			l3->next = new ListNode(temp);
		}

		return pl3Head->next;
    }
};

// class Solution {
// public:
// 	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
// 		int l1_length = 0;
// 		int l2_length = 0;
// 		ListNode *pNode1 = l1;
// 		ListNode *pNode2 = l2;
// 		//�������ؽ���������ͷ����
// 		ListNode *l3 = new ListNode(-1);
// 		//ָ��ͷ�ڵ����ڷ�����������
// 		ListNode *pNode4 = l3;
// 		int temp = 0;
// 		while (pNode1 != NULL && pNode2 != NULL)
// 		{
// 			ListNode *pNode3 = new ListNode((temp + pNode1->val + pNode2->val) % 10);
// 			temp = (temp + pNode1->val + pNode2->val) / 10;
// 			pNode1 = pNode1->next;
// 			pNode2 = pNode2->next;
// 			l3->next = pNode3;
// 			l3 = l3->next;
// 		}
// 		while (pNode1 != NULL)
// 		{
// 			ListNode *pNode3 = new ListNode((temp + pNode1->val) % 10);
// 			temp = (temp + pNode1->val) / 10;
// 			pNode1 = pNode1->next;
// 			l3->next = pNode3;
// 			l3 = l3->next;
// 		}
// 		while (pNode2 != NULL)
// 		{
// 			ListNode *pNode3 = new ListNode((temp + pNode2->val) % 10);
// 			temp = (temp + pNode2->val) / 10;
// 			pNode2 = pNode2->next;
// 			l3->next = pNode3;
// 			l3 = l3->next;
// 		}
// 		if (temp != 0)
// 		{
// 			ListNode *pNode3 = new ListNode(temp);
// 			l3->next = pNode3;
// 			l3 = l3->next;
// 		}
// 		return pNode4->next;
// 	}
// };
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
