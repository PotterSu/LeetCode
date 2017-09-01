
/*
79. Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

解题思路：深搜
          首先找到board一个等于word首字母的位置，然后上下左右进行递归深搜，直到最后一个字母完全匹配，返回结果
		  注意：要设置一个path矩阵用来存储访问过哪些地方，防止在一次递归中重复访问，当前递归层结束后重置path[i][j]
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

bool dfs(int i, int j, vector<vector<char>> board, string word, int wordposition, vector<vector<bool>>& path)
{
	if (wordposition == word.length() - 1)
	{
		return true;
	}
	path[i][j] = true;
	if (i + 1 < board.size() && !path[i + 1][j] && board[i + 1][j] == word[wordposition + 1])
	{
		if (dfs(i + 1, j, board, word, wordposition + 1, path))
			return true;
	}
	if (i - 1 >= 0 && !path[i - 1][j] && board[i - 1][j] == word[wordposition + 1])
	{
		if (dfs(i - 1, j, board, word, wordposition + 1, path))
			return true;
	}
	if (j - 1 >= 0 && !path[i][j - 1] && board[i][j - 1] == word[wordposition + 1])
	{
		if (dfs(i, j - 1, board, word, wordposition + 1, path))
			return true;
	}

	if (j + 1 < board[0].size() && !path[i][j + 1] && board[i][j + 1] == word[wordposition + 1])
	{
		if (dfs(i, j + 1, board, word, wordposition + 1, path))
			return true;
	}
	path[i][j] = false;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	bool result = false;
	vector<vector<bool>> path(board.size(), vector<bool>(board[0].size(), false));
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == word[0])
				result = dfs(i, j, board, word, 0, path);
			if (result)
				return result;
		}
	}
	return result;
}

int main()
{
	vector<vector<char>> board;
	vector<char> temp;
	temp.push_back('A');
	temp.push_back('B');
	temp.push_back('C');
	temp.push_back('E');
	board.push_back(temp);
	vector<char> temp1;
	temp1.push_back('S');
	temp1.push_back('F');
	temp1.push_back('C');
	temp1.push_back('S');
	board.push_back(temp1);
	vector<char> temp2;
	temp2.push_back('A');
	temp2.push_back('D');
	temp2.push_back('E');
	temp2.push_back('E');
	board.push_back(temp2);
	string word = "ABCCED";
	bool status = exist(board, word);
	cout << status << endl;
	while (1);
	return 0;
}

