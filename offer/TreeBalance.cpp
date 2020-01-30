/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
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

bool DFS(TreeNode* pRoot, int& depth)
{
	if(pRoot == NULL)
	{
		depth = 0;
		return true;
	}
	else if(pRoot->left == NULL && pRoot->right == NULL)
	{
		depth = 1;
		return true;
	}
	else if(pRoot->left == NULL || pRoot->right == NULL)
	{
		int depthLeft = 0;
		int depthRight = 0;
		bool statusLeft = DFS(pRoot->left, depthLeft);
		bool statusRight = DFS(pRoot->right, depthRight);
		depth = (depthLeft >= depthRight ? depthLeft : depthRight) + 1;
		if(abs(depthLeft - depthRight) <= 1)
			return true;
		else
			return false;
	}
	else
	{
		int depthLeft = 0;
		int depthRight = 0;
		bool statusLeft = DFS(pRoot->left, depthLeft);
		bool statusRight = DFS(pRoot->right, depthRight);
		depth = (depthLeft >= depthRight ? depthLeft : depthRight) + 1;
		if(abs(depthLeft - depthRight) <= 1)
			return statusLeft && statusRight;
		else
			return false;
	}
}

bool IsBalanced_Solution(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return false;
	else if(pRoot->left == NULL && pRoot->right == NULL)
		return true;
	else if(pRoot->left == NULL || pRoot->right == NULL)
	{
		int depthLeft = 0;
		int depthRight = 0;
		bool statusLeft = DFS(pRoot->left, depthLeft);
		bool statusRight = DFS(pRoot->right, depthRight);
		if(abs(depthLeft - depthRight) <= 1)
			return true;
		else
			return false;
	}
	else
	{
		int depthLeft = 0;
		int depthRight = 0;
		bool statusLeft = DFS(pRoot->left, depthLeft);
		bool statusRight = DFS(pRoot->right, depthRight);
		if(abs(depthLeft - depthRight) <= 1)
			return statusLeft && statusRight;
		else
			return false;
	}
}

int main()
{
	TreeNode* root = new TreeNode(50);
	root->left = new TreeNode(45);
	root->left->left = new TreeNode(44);
	root->left->right = new TreeNode(46);
	root->left->left->left = new TreeNode(43);
	root->right = new TreeNode(65);
	root->right->right = new TreeNode(43);
	// TreeNode* root = new TreeNode(50);
	// root->left = new TreeNode(45);
	// root->left->left = new TreeNode(44);
	// root->left->left->left = new TreeNode(43);
	// root->right = new TreeNode(65);
	// root->right->right = new TreeNode(70);

    bool result = IsBalanced_Solution(root);
	cout << result << endl;

	return 0;
}
