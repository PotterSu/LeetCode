/*
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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

int FindSubDepth(TreeNode* pRoot, int depth)
{
	if(pRoot == NULL)
		return depth;
	depth += 1;
	int depthLeft = FindSubDepth(pRoot->left, depth);
	int depthRight = FindSubDepth(pRoot->right, depth);

	return depthLeft >= depthRight ? depthLeft : depthRight;
}

int TreeDepth(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return 0;
	int depth = 1;
	int depthLeft = FindSubDepth(pRoot->left, depth);
	int depthRight = FindSubDepth(pRoot->right, depth);

	return depthLeft >= depthRight ? depthLeft : depthRight;
}

int main()
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->right = new TreeNode(6);
	root->left->left = new TreeNode(6);
	root->left->left->left = new TreeNode(6);
	root->right = new TreeNode(11);
	root->right->right = new TreeNode(12);

	int depth = TreeDepth(root);
	cout << depth << endl;

	return 0;
}
