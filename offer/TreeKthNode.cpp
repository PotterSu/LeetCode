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

TreeNode* DFS(TreeNode* pRoot, int k, int& depth)
{
	if(pRoot == NULL)
	{
		return pRoot;
	}
	TreeNode* result = DFS(pRoot->left, k, depth);
	if(depth + 1 > k)
		return result;
	depth += 1;
	if(depth == k)
		return pRoot;
	if(depth < k)
	{
		result = DFS(pRoot->right, k, depth);
		return result;
	}
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if(pRoot == NULL)
		return NULL;
	int depth = 0;
	TreeNode* result = DFS(pRoot->left, k, depth);
	if(depth + 1 > k)
		return result;
	depth += 1;
	if(depth == k)
		return pRoot;
	if(depth < k)
	{
		result = DFS(pRoot->right, k, depth);
		return result;
	}
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(7);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(11);

    TreeNode* result = KthNode(root, 5);
	cout << result->val << endl;

	return 0;
}
