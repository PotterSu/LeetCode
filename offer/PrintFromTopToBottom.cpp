/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

#include "iostream"
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

vector<int> PrintFromTopToBottom(TreeNode* root)
{
	vector<int> result;
	if(root == NULL)
		return result;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode* t = q.front();
		q.pop();
		result.push_back(t->val);
		if(t->left != NULL)
		{
			q.push(t->left);
		}
		if(t->right != NULL)
		{
			q.push(t->right);
		}
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

	vector<int> result = PrintFromTopToBottom(root);
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}
