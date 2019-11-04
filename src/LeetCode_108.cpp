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


TreeNode* sortedArrayToBST(vector<int>& nums)
{
    if(nums.size() == 0)
    {
        return NULL;
    }
    if(nums.size() == 1)
    {
        return new TreeNode(nums[0]);
    }

    int middle = nums.size() / 2;
    cout << "middle " << middle << endl;
    for(int i = 0; i < nums.size(); i++)
    {
        cout << " " << nums[i];
    }
    cout << endl;
    vector<int> nums_left(nums.begin(), nums.begin() + middle);
    vector<int> nums_right(nums.begin() + middle + 1, nums.end());
    TreeNode* t = new TreeNode(nums[middle]);
    t->left = sortedArrayToBST(nums_left);
    t->right = sortedArrayToBST(nums_right);
    return t;
}


int main()
{
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-3);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(9);
    TreeNode* result = sortedArrayToBST(nums);

	return 0;
}
