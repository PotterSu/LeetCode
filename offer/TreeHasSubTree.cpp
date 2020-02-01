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

bool isEqual(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(pRoot1 == NULL && pRoot2 == NULL)
		return true;
	else if(pRoot1 != NULL && pRoot2 == NULL)
		return true;
	else if(pRoot1 == NULL && pRoot2 != NULL)
		return false;
	else if(pRoot1->val != pRoot2->val)
		return false;
	else
	{
		return isEqual(pRoot1->left, pRoot2->left) && isEqual(pRoot1->right, pRoot2->right);
	}
}

bool DFS(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(pRoot1 == NULL)
		return false;
	bool statusRoot = isEqual(pRoot1, pRoot2);
	bool statusLeft = isEqual(pRoot1->left, pRoot2);
	bool statusRight = isEqual(pRoot1->right, pRoot2);
	return statusRoot || statusLeft || statusRight;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(pRoot1 == NULL || pRoot2 == NULL)
		return false;
	return DFS(pRoot1, pRoot2);
}

int main()
{
    TreeNode* root1 = new TreeNode(8);
    root1->left = new TreeNode(7);
    root1->right = new TreeNode(10);
    root1->left->left = new TreeNode(5);
    root1->right->right = new TreeNode(11);

	TreeNode* root2 = new TreeNode(7);
    root2->left = new TreeNode(5);
    // root2->right = new TreeNode(10);
    // root2->left->left = new TreeNode(5);
    // root2->right->right = new TreeNode(11);

    bool result = HasSubtree(root1, root2);
	cout << result << endl;

	return 0;
}
