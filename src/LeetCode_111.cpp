/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
 */

#include "iostream"
#include "vector"
#include "string"
#include "queue"

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct TreeNode
 {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int minDepth(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int depth = 0;
    int depthLeft = minDepth(root->left) + 1;
    int depthRight = minDepth(root->right) + 1;
    if(depthLeft == 1)
    {
        depth = depthRight;
        return depth;
    }
    if(depthRight == 1)
    {
        depth = depthLeft;
        return depth;
    }

    return depthLeft <= depthRight ? depthLeft : depthRight;
}

int main()
{
    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);

    // TreeNode* t2 = new TreeNode(1);
    // t2->left = new TreeNode(2);
    // t2->right = new TreeNode(2);
    // t2->left->left = new TreeNode(3);
    // t2->left->right = new TreeNode(3);
    // t2->left->left->left = new TreeNode(4);
    // t2->left->left->right = new TreeNode(4);
    // TreeNode* t3 = new TreeNode(1);
    // t3->left = new TreeNode(2);
    // t3->left->left = new TreeNode(3);
    // t3->left->left->left = new TreeNode(4);
    // t3->right = new TreeNode(2);
    // t3->right->right = new TreeNode(3);
    // t3->right->right->right = new TreeNode(4);

    int result = minDepth(t1);
    cout << result << endl;
	return 0;
}
