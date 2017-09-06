/*
98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
2
/ \
1   3
Binary tree [2,1,3], return true.
Example 2:
1
/ \
2   3
Binary tree [1,2,3], return false.

解题思路：递归的思想
          如果当前节点为空，直接返回true
		  如果当前节点小于传入的最小范围或者当前节点大于传入的最大范围，return false
		  接下来进行左右子树递归，并传入子树允许的取值区间
		  对于根结点的取值区间为LONG_MIN-LONG_MAX
		  对于左子树的取值区间为LONG_MIN-root->val
		  对于右子树的取值区间为root->val-LONG_MAX
		  不断递归，只有返回值都为true时才是搜索二叉树
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST1(root, LONG_MIN, LONG_MAX);
	}
	bool isValidBST1(TreeNode * root, long minValue, long maxValue)
	{
		if (root == NULL)
			return true;

		if (root->val <= minValue || root->val >= maxValue)
		{
			return false;
		}
		return isValidBST1(root->left, minValue, root->val) && isValidBST1(root->right, root->val, maxValue);
	}
};

