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

����˼·���ݹ��˼��
          �����ǰ�ڵ�Ϊ�գ�ֱ�ӷ���true
		  �����ǰ�ڵ�С�ڴ������С��Χ���ߵ�ǰ�ڵ���ڴ�������Χ��return false
		  �������������������ݹ飬���������������ȡֵ����
		  ���ڸ�����ȡֵ����ΪLONG_MIN-LONG_MAX
		  ������������ȡֵ����ΪLONG_MIN-root->val
		  ������������ȡֵ����Ϊroot->val-LONG_MAX
		  ���ϵݹ飬ֻ�з���ֵ��Ϊtrueʱ��������������
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

