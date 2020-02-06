/*
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
从而使得内存中建立起来的二叉树可以持久保存。
序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，
序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
*/

#include "iostream"

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

char* Serialize(TreeNode *root)
{
    if(root == NULL)
	{
		return "#";
	}
	else
	{
		char* left = Serialize(root->left);
		char* right = Serialize(root->right);
		string r = to_string(root->val) + ',';
		char* ret = new char[strlen(left) + strlen(right) + sizeof(r)];
		strcpy(ret, r.c_str());
		strcat(ret, left);
		strcat(ret, right);
		return ret;
	}
}

TreeNode* decode(char*& str) {
	if(str[0] == '#')
	{
		str++;
		return NULL;
	}
	int num = 0;
	while(*str != ',')
	{
		num = num * 10 + (*(str++) - '0');
	}
	str++;
	TreeNode* root = new TreeNode(num);
	root->left = decode(str);
	root->right = decode(str);
	return root;
}

TreeNode* Deserialize(char *str)
{
	return decode(str);
}

int main()
{
	char* str = "1,2,###";
	TreeNode* rootResult = Deserialize(str);
    char* strResult = Serialize(rootResult);
	while(*strResult != '\0')
	{
		cout << *strResult;
		strResult++;
	}

	return 0;
}
