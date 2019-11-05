/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
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

int getDepth(TreeNode* t)
{
    if(t == NULL)
    {
        return 0;
    }
    int depth_left = getDepth(t->left);
    int depth_right = getDepth(t->right);
    int depth_max = depth_left >= depth_right ? depth_left : depth_right;
    return depth_max + 1;
}

bool isBalanced(TreeNode* root)
{
    if(root == NULL)
        return true;
    if(!isBalanced(root->left) || !isBalanced(root->right))
    {
        return false;
    }
    int depth_left = getDepth(root->left);
    int depth_right = getDepth(root->right);
    if(abs(depth_left - depth_right) > 1)
        return false;
    return true;
}

int main()
{
    // TreeNode* t1 = new TreeNode(3);
    // t1->left = new TreeNode(9);
    // t1->right = new TreeNode(20);
    // t1->right->left = new TreeNode(15);
    // t1->right->right = new TreeNode(7);

    // TreeNode* t2 = new TreeNode(1);
    // t2->left = new TreeNode(2);
    // t2->right = new TreeNode(2);
    // t2->left->left = new TreeNode(3);
    // t2->left->right = new TreeNode(3);
    // t2->left->left->left = new TreeNode(4);
    // t2->left->left->right = new TreeNode(4);
    TreeNode* t3 = new TreeNode(1);
    t3->left = new TreeNode(2);
    t3->left->left = new TreeNode(3);
    t3->left->left->left = new TreeNode(4);
    t3->right = new TreeNode(2);
    t3->right->right = new TreeNode(3);
    t3->right->right->right = new TreeNode(4);

    bool result = isBalanced(t3);
    cout << result << endl;
	return 0;
}
