/*
19.
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

解题思路：首先要知道链表l1有多长
          然后创建一个返回链表的头节点pNode，指向链表l1，这是为了如果需要，可以删除l1第一个数
		  再创建个指针lh指向pNode，这是为了返回完整的pNode链表
		  接下来就根据l1的长度与需要删除的位置之差进行pNode指针移动，删除即可
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
		//创建返回链表的头节点
		pNode = new ListNode(-1);
		pNode->next = head;
		//指向返回链表的头节点，便于返回
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