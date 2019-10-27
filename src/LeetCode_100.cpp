/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
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


bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(p == NULL || q == NULL)
    {
        if(p != q)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool result = true;
    if(p->val == q->val)
    {
        bool result_left = isSameTree(p->left, q->left);
        bool result_right = isSameTree(p->right, q->right);
        result = (result_left && result_right);
        return result;
    }
    else
    {
        return !result;
    }
}

int main()
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    // t1->right = new TreeNode(3);

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    // t2->right = new TreeNode(3);

    bool result = isSameTree(t1, t2);
    cout << result << endl;

	return 0;
}
