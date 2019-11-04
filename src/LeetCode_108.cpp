/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
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

void sort(TreeNode* t, int left, int right, vector<int> nums)
{
    int middle = (left + right) / 2;
    t = new TreeNodenums[middle];
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    int right = nums.size() - 1;
    int left = 0;
    int middle = (left + right) / 2;

    TreeNode* t = new TreeNode(nums[len / 2]);
    sort(t->left, left, middle - 1);
    sort(t->right, middle + 1, right);
}


int main()
{
    TreeNode* t1 = new TreeNode(3);
    // t1->left = new TreeNode(9);
    // t1->right = new TreeNode(20);
    // t1->right->left = new TreeNode(15);
    // t1->right->right = new TreeNode(7);

    // TreeNode* t2 = new TreeNode(1);
    // t2->left = new TreeNode(2);
    // t2->right = new TreeNode(3);
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-3);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(9);
    vector<vector<int>> result = sortedArrayToBST(nums);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
