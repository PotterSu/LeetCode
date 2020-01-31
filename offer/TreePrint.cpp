/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
	while(!q.empty())
	{
		int size = q.size();
		vector<int> temp;
		for(int i = 0; i < size; i++)
		{
			temp.push_back(q.front()->val);
			if(q.front()->left != NULL)
				q.push(q.front()->left);
			if(q.front()->right != NULL)
				q.push(q.front()->right);
			q.pop();
		}
		result.push_back(temp);
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
