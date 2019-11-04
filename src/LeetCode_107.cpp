/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
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

void leveOrderBottom(queue<TreeNode*> q, vector<vector<int>>& result)
{
    if (q.empty()) return;
    vector<int> resultTemp;
    queue<TreeNode*> qnext;
    while(!q.empty())
    {
        TreeNode* q_front = q.front();
        resultTemp.push_back(q_front->val);
        q.pop();
        if(q_front->left != NULL)
        {
            qnext.push(q_front->left);
        }
        if(q_front->right != NULL)
        {
            qnext.push(q_front->right);
        }
    }
    leveOrderBottom(qnext, result);
    result.push_back(resultTemp);
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    queue<TreeNode*> q;
    vector<vector<int>> result;
    if(root != NULL)
    {
        q.push(root);
    }
    leveOrderBottom(q, result);
    return result;
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

    vector<vector<int>> result = levelOrderBottom(t1);
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
