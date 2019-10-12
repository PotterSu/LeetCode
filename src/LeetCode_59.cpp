/*
59. Spiral Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]

解题思路：首先初始化vector
		  然后按照上行 右列 下行 左列的顺序将1-n*n个数插入vector中，直到n*n个数插完
		  注意的是，当上下行插完，now_row+1;
		  当上下列插完，now_col+1
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n, vector<int>(n));
	int now_row = 0;
	int now_col = 0;
	//当前插入的数，从1开始
	int now_num = 1;
	while (now_num <= n*n)
	{
		//插入最上行
		for (int j = now_col; j < n - now_col; j++)
		{
			int i = now_row;
			matrix[i][j] = now_num;
			now_num++;
		}
		//插入最右列
		for (int i = now_row + 1; i < n - now_row; i++)
		{
			int j = n - now_col - 1;
			matrix[i][j] = now_num;
			now_num++;
		}
		//插入最下行
		for (int j = n - now_col - 2; j >= now_col; j--)
		{
			int i = n - now_row - 1;
			matrix[i][j] = now_num;
			now_num++;
		}
		//当前上下行已填入完全，将now_row+1，为下次4个方向插入做准备
		now_row++;
		//插入最左列
		for (int i = n - now_row - 1; i >= now_row; i--)
		{
			int j = now_col;
			matrix[i][j] = now_num;
			now_num++;
		}
		//当前左右列已填入完全，将now_col+1，为下次4个方向插入做准备
		now_col++;
	}
	return matrix;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> result = generateMatrix(n);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

