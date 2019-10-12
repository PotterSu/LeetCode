/*
19.
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.

����˼·������Ҫ֪������l1�ж೤
          Ȼ�󴴽�һ�����������ͷ�ڵ�pNode��ָ������l1������Ϊ�������Ҫ������ɾ��l1��һ����
		  �ٴ�����ָ��lhָ��pNode������Ϊ�˷���������pNode����
		  �������͸���l1�ĳ�������Ҫɾ����λ��֮�����pNodeָ���ƶ���ɾ������
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *pNode = head;
		int nLength = 0;
		while (pNode != NULL)
		{
			nLength++;
			pNode = pNode->next;
		}
		//�������������ͷ�ڵ�
		pNode = new ListNode(-1);
		pNode->next = head;
		//ָ�򷵻������ͷ�ڵ㣬���ڷ���
		ListNode *lh = pNode;
		//-1 0 1 2 3 4
		int nIndex = 0;
		while (nIndex < nLength - n)
		{
			pNode = pNode->next;
			nIndex++;
		}
		pNode->next = pNode->next->next;
		return lh->next;
	}
};
int main()
{
	Solution* solution = new Solution();
	ListNode *l1 = new ListNode(1);
	ListNode *l12 = new ListNode(2);
	ListNode *l13 = new ListNode(3);
	l1->next = l12;
	l12->next = l13;

	ListNode *l3 = solution->removeNthFromEnd(l1, 3);
	while (l3 != NULL)
	{
		std::cout << l3->val << std::endl;
		l3 = l3->next;
	}

	delete(solution);
	delete(l1);
	delete(l3);
	return 0;
}