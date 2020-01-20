/*
二叉树的镜像定义：源二叉树
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
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

void Mirror(TreeNode *pRoot)
{
    if(pRoot == NULL)
        return;

    TreeNode* pTemp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = pTemp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);

    Mirror(root);

    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    cout << root->right->left->val << endl;
    cout << root->right->right->val << endl;

	return 0;
}
