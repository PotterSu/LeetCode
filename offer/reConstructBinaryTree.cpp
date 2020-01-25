/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
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

// vector<int> pre{1,2,4,3,5,6};
// vector<int> vin{4,2,1,5,3,6};
// 2
TreeNode* DFS(vector<int> pre, vector<int> vin, int preStart, int preEnd,
												int vinStart, int vinEnd)
{
	TreeNode* root;
	if(preStart > preEnd)
	{
		return NULL;
	}
	if(preStart == preEnd)
	{
		root = new TreeNode(pre[preStart]);
		return root;
	}
	root = new TreeNode(pre[preStart]);
	int vinRootIndex;
	for(int i = vinStart; i <= vinEnd; i++)
	{
		if(vin[i] == pre[preStart])
		{
			vinRootIndex = i;
		}
	}
	int preLength = vinRootIndex - vinStart - 1; //
	root->left = DFS(pre, vin, preStart + 1, preStart + 1 + preLength, vinStart, vinRootIndex - 1);
	root->right = DFS(pre, vin, preStart + 1 + preLength + 1, preEnd, vinRootIndex + 1, vinEnd);

	return root;
}

// vector<int> pre{1,2,4,7,3,5,6,8};
// vector<int> vin{4,7,2,1,5,3,8,6};
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
{
	if(pre.size() != vin.size())
		return NULL;
	if(pre.size() == 0)
		return NULL;
	TreeNode* root = new TreeNode(pre[0]);
	int vinRootIndex;
	for(int i = 0; i < vin.size(); i++)
	{
		if(vin[i] == pre[0])
		{
			vinRootIndex = i;
		}
	}
	int preStart = 0;
	int preEnd = pre.size() - 1;
	int preLength = vinRootIndex - 0 - 1;
	root->left = DFS(pre, vin, preStart + 1, preStart + 1 + preLength, 0, vinRootIndex - 1);
	root->right = DFS(pre, vin, preStart + 1 + preLength + 1, preEnd, vinRootIndex + 1, vin.size() - 1);

	return root;
}

int main()
{
	vector<int> pre{1,2,4,3,5,6};
	vector<int> vin{4,2,1,5,3,6};
    TreeNode* tree = reConstructBinaryTree(pre, vin);

    cout << tree->val << endl;
    cout << tree->left->val << endl;
    cout << tree->right->val << endl;
    cout << tree->right->left->val << endl;
    cout << tree->right->right->val << endl;

	return 0;
}
