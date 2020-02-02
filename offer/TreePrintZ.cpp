/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，
其他行以此类推。
*/

#include "iostream"
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

vector<vector<int> > Print(TreeNode* pRoot)
{
	vector<vector<int>> result;
    if(pRoot == NULL)
	    return result;
	queue<TreeNode*> q;
	q.push(pRoot);
	int depth = 1;
	while(!q.empty())
	{
		vector<TreeNode*> tempNode;
		//保存当层的节点
		int size = q.size();
		for(int i = 0; i < size; i++)
		{
			tempNode.push_back(q.front());
			if(q.front()->left != NULL)
				q.push(q.front()->left);
			if(q.front()->right != NULL)
				q.push(q.front()->right);
			q.pop();
		}
		//决定正向遍历还是反向遍历
		vector<int> tempResult;
		if(depth % 2 == 1)
		{
			for(int i = 0; i < tempNode.size(); i++)
			{
				tempResult.push_back(tempNode[i]->val);
			}
		}
		else if(depth % 2 == 0)
		{
			for(int i = tempNode.size() - 1; i >= 0; i--)
			{
				tempResult.push_back(tempNode[i]->val);
			}
		}

		result.push_back(tempResult);
		depth++;
	}
	return result;
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);

    vector<vector<int>> result = Print(root);

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
