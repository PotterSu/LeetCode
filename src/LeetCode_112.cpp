/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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

bool depth(TreeNode* root, int cur_sum, int sum)
{
    bool flag_left = false;
    bool flag_right = false;
    if(root->left == NULL && root->right == NULL)
    {
        if(cur_sum + root->val == sum)
            return true;
        else
            return false;
    }
    if(root->left != NULL)
    {
        flag_left = depth(root->left, cur_sum + root->val, sum);
    }
    if(root->right != NULL)
    {
        flag_right = depth(root->right, cur_sum + root->val, sum);
    }
    return flag_left || flag_right;
}

bool hasPathSum(TreeNode* root, int sum)
{
    if(root == NULL)
        return false;
    bool flag_left = false;
    bool flag_right = false;
    if(root->left == NULL && root->right == NULL)
    {
        if(root->val == sum)
            return true;
    }
    if(root->left != NULL)
    {
        flag_left = depth(root->left, root->val, sum);
    }
    if(root->right != NULL)
    {
        flag_right = depth(root->right, root->val, sum);
    }
    return flag_left || flag_right;
}

int main()
{
    TreeNode* t1 = new TreeNode(5);
    t1->left = new TreeNode(4);
    t1->left->left = new TreeNode(11);
    t1->left->left->left = new TreeNode(7);
    t1->left->left->right = new TreeNode(1);
    t1->right = new TreeNode(8);
    t1->right->left = new TreeNode(13);
    t1->right->right = new TreeNode(4);

    bool result = hasPathSum(t1, 26);
    cout << result << endl;
	return 0;
}
