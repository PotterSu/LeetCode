/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

#include "iostream"
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

void LinkNode(vector<TreeNode*>& list)
{
	for(int i = 0; i < list.size() - 1; i++)
	{
		list[i]->right = list[i+1];
		list[i+1]->left = list[i];
	}
}

void mid(TreeNode* root, vector<TreeNode*>& list)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		mid(root->left, list);
		list.push_back(root);
		mid(root->right, list);
	}
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if(pRootOfTree == NULL)
		return pRootOfTree;
	vector<TreeNode*> list;
	mid(pRootOfTree, list);
	LinkNode(list);

	return list[0];
}

int main()
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->right = new TreeNode(6);
	root->right = new TreeNode(11);
	root->right->right = new TreeNode(12);

	TreeNode* tree = Convert(root);

	return 0;
}
