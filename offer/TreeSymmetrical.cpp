/*
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
  	  8
	/  \
   6   6
  / \  / \
 5  7 7  5
*/

#include "iostream"

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

bool DFS(TreeNode* pLeft, TreeNode* pRight)
{
	if(pLeft == NULL && pRight == NULL)
		return true;
	else if(pLeft == NULL || pRight == NULL)
		return false;
	else if(pLeft->val == pRight->val)
	{
		return DFS(pLeft->right, pRight->left) && DFS(pLeft->left, pRight->right);
	}
	else
	{
		return false;
	}
}

bool isSymmetrical(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return true;
	return DFS(pRoot->left, pRoot->right);
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(10);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    bool result = isSymmetrical(root);
	cout << result << endl;

	return 0;
}
