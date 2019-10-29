/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
 */

#include "iostream"
#include "vector"
#include "string"
#include "stack"

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

int maxDepth(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = 1 + maxDepth(root->left);
    int r = 1 + maxDepth(root->right);

    return l >= r ? l : r;
}


int main()
{
    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->left->right = new TreeNode(7);

    // TreeNode* t2 = new TreeNode(1);
    // t2->left = new TreeNode(2);
    // t2->right = new TreeNode(3);

    int result = maxDepth(t1);
    cout << result << endl;

	return 0;
}
