/*
73. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

解题思路：利用矩阵第一行和第一列来记录整个矩阵的各行各列是否存在0
	      首先看第一行和第一列是否有0
		  然后从（1，1）到（m,n）依次检查，有0就对第一行或第一列重新赋值
		  然后从第二行第二列开始，根据第一行、第一列是否为0情况赋值0
		  最后赋值第一行、第一列
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	//记录第一行 第一列是否有0的状态
	int flag_col = 0;
	int flag_row = 0;
	//遍历第一行 第一列，有零更新状态
	for (int i = 0; i < m; i++)
		if (matrix[i][0] == 0)
			flag_col = 1;
	for (int j = 0; j < n; j++)
		if (matrix[0][j] == 0)
			flag_row = 1;
	//用第一行 第一列记录整个矩阵的各行各列的0情况
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
		if (matrix[i][j] == 0)
		{
			matrix[i][0] = 0;
			matrix[0][j] = 0;
		}
		}
	//更新矩阵
	for (int j = 1; j < n; j++)
		if (matrix[0][j] == 0)
			for (int i = 0; i < m; i++)
				matrix[i][j] = 0;
	for (int i = 1; i < m; i++)
		if (matrix[i][0] == 0)
			for (int j = 1; j < n; j++)
				matrix[i][j] = 0;
	//最后更新第一行 第一列情况
	if (flag_col)
		for (int i = 0; i < m; i++)
			matrix[i][0] = 0;
	if (flag_row)
		for (int j = 0; j < n; j++)
			matrix[0][j] = 0;
	//输出
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << " ";
	}
}

int main()
{
	vector<vector<int >> matrix;
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	vector<int> temp1;
	temp1.push_back(1);
	temp1.push_back(2);
	temp1.push_back(3);
	vector<int> temp2;
	temp2.push_back(1);
	temp2.push_back(2);
	temp2.push_back(0);
	matrix.push_back(temp);
	matrix.push_back(temp1);
	matrix.push_back(temp2);
	setZeroes(matrix);
	return 0;
}