/*
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false
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
