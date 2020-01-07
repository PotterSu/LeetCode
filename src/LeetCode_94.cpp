/*
94. 二叉树的中序遍历
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> result;
    if(root == NULL)
        return result;
    //左不为空
    if(root->left != NULL)
    {
        result = inorderTraversal(root->left);
    }
    result.push_back(root->val);
    std::vector<int> resultRight;
    if(root->right != NULL)
    {
        resultRight = inorderTraversal(root->right);
    }
    for(int i = 0; i < resultRight.size(); i++)
    {
        result.push_back(resultRight[i]);
    }
    return result;
}

int main()
{
    TreeNode* t = new TreeNode(1);
    TreeNode* rightChild = new TreeNode(2);
    TreeNode* leftChild = new TreeNode(3);
    t->right = rightChild;
    t->right->left = leftChild;

    std::vector<int> result = inorderTraversal(t);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    delete leftChild;
    leftChild = NULL;
    delete rightChild;
    rightChild = NULL;
    delete t;
    t = NULL;

	return 0;
}
