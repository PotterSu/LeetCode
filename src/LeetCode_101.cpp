/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
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


 bool isMirror(TreeNode* r1, TreeNode* r2)
 {
     if(r1 == NULL || r2 == NULL)
     {
         if(r1 == r2)
         {
             return true;
         }
         else
         {
             return false;
         }
     }
     if(r1->val == r2->val)
     {
         return isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
     }
     return false;
 }

bool isSymmetric(TreeNode* root)
{
    if(root == NULL)
        return true;
    return isMirror(root->left, root->right) && isMirror(root->right, root->left);
}


int main()
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->left->left = new TreeNode(2);
    t1->left->right = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->right->left = new TreeNode(3);
    t1->right->right = new TreeNode(2);

    // TreeNode* t2 = new TreeNode(1);
    // t2->left = new TreeNode(2);
    // t2->right = new TreeNode(3);

    bool result = isSymmetric(t1);
    cout << result << endl;

	return 0;
}
