/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

#include "iostream"
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

RandomListNode* split(RandomListNode* pHead)
{
	RandomListNode* p = pHead;
	RandomListNode* pCopy = pHead->next;
	RandomListNode* pReturn = pCopy;
	while(p != NULL && pCopy != NULL)
	{
		p->next = pCopy->next;
		p = p->next;
		if(p == NULL)
		{
			pCopy->next = NULL;
		}
		else
		{
			pCopy->next = p->next;
			pCopy = pCopy->next;
		}
	}
	return pReturn;
}

void initRandom(RandomListNode* pHead)
{
	RandomListNode* p = pHead;
	RandomListNode* pCopy = pHead->next;
	while(p != NULL && pCopy != NULL)
	{
		if(p->random != NULL)
		{
			pCopy->random = p->random->next;
		}
		p = pCopy->next;
		if(p != NULL)
		{
			pCopy = p->next;
		}
		else
		{
			pCopy = NULL;
		}
	}
}

void copyNode(RandomListNode* pHead)
{
	RandomListNode* p = pHead;
	while(p != NULL)
	{
		RandomListNode* pCopy = new RandomListNode(p->label);
		pCopy->next = p->next;
		p->next = pCopy;
		p = pCopy->next;
	}
}

RandomListNode* Clone(RandomListNode* pHead)
{
	if(pHead == NULL)
		return NULL;
	copyNode(pHead);
	initRandom(pHead);
	return split(pHead);
}

int main()
{
	RandomListNode* l1 = new RandomListNode(1);
	RandomListNode* l2 = new RandomListNode(1);
	RandomListNode* l3 = new RandomListNode(1);
	RandomListNode* l4 = new RandomListNode(1);

	l1->next = l2;
	l1->random = l3;
	l2->next = l3;
	l2->random = l4;
	l3->next = l4;
	l3->random = l1;

    RandomListNode* result = Clone(l1);

	return 0;
}
