/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
*/

#include "iostream"
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

void Calculate(vector<vector<int>>& result, vector<int> temp, TreeNode* root, int sum, int expectNumber)
{
	if(root == NULL)
		return;
	//如果当前节点是叶子节点
	if(root->left == NULL && root->right == NULL)
	{
		sum += root->val;
		temp.push_back(root->val);
		if(sum == expectNumber)
			result.push_back(temp);
	}
	else
	{
		sum += root->val;
		temp.push_back(root->val);
		Calculate(result, temp, root->left, sum, expectNumber);
		Calculate(result, temp, root->right, sum, expectNumber);
	}
}

vector<vector<int>> FindPath(TreeNode* root,int expectNumber)
{
	vector<int> temp;
	vector<vector<int>> result;
	if(root == NULL)
		return result;
	int sum = 0;

	Calculate(result, temp, root, sum, expectNumber);
	return result;
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(11);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);

    vector<vector<int>> result = FindPath(root, 19);
	cout << result.size() << endl;

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
