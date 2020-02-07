/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

#include "iostream"

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if(pNode == NULL)
		return NULL;

	if(pNode->right != NULL)
	{
		TreeLinkNode* pTemp = pNode->right;
		while(pTemp->left != NULL)
		{
			pTemp = pTemp->left;
		}
		return pTemp;
	}
	if(pNode->right == NULL)
	{
		TreeLinkNode* pCurrent = pNode;
		TreeLinkNode* pParent = pNode->next;
		while(pParent != NULL && pParent->right == pCurrent)
		{
			pCurrent = pParent;
			pParent = pCurrent->next;
		}
		return pParent;
	}
}

int main()
{


	return 0;
}
