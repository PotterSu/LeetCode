/*
2.
���������ǿ���������ʾ�����Ǹ�������λ������������ʽ�洢�����ǵ�ÿ���ڵ�ֻ�洢�������֡����������ӷ���һ���µ�������

�����Լ����������� 0 ֮�⣬���������ֶ��������㿪ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
������7 -> 0 -> 8
ԭ����342 + 465 = 807

����˼·�����ȴ���l3��������ͷ�ڵ㣬�����ӵĽ���ֱ�Ӽӵ�l3β��������pNode4ָ��l3ͷ�ڵ����ڷ���������������
          ��������l1��l2�������ֽ��мӺͣ�ע����λ����
          Ȼ����l1����l2�����Ĳ��ֵ������мӺ�
		  �����ж�����һ�μӺ��Ƿ��н�λ���н�λ����Ҫ�ٴ������ڵ�
		  ����pNode4����
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
		int l1_length = 0;
		int l2_length = 0;
		ListNode *pNode1 = l1;
		ListNode *pNode2 = l2;
		//�������ؽ���������ͷ����
		ListNode *l3 = new ListNode(-1);
		//ָ��ͷ�ڵ����ڷ�����������
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
