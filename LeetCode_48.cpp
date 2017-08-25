/*
48. Rotate Image

Given input matrix =
[
[ 5, 1, 9,11],
[ 2, 4, 8,10],
[13, 3, 6, 7],
[15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
[15,13, 2, 5],
[14, 3, 4, 1],
[12, 6, 8, 9],
[16, 7,10,11]
]

解题思路：首先将矩阵沿对角线对折，然后将对折后的结果沿中轴线左右翻折
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;
void rotate(vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = i; j < matrix[i].size(); j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size() / 2; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][matrix[i].size() - j - 1];
			matrix[i][matrix[i].size() - j - 1] = temp;
		}
	}
}

int main()
{
	vector<vector<int>> matrix;
	vector<int> row1;
	row1.push_back(5);
	row1.push_back(1);
	row1.push_back(9);
	row1.push_back(11);
	matrix.push_back(row1);
	vector<int> row2;
	row2.push_back(2);
	row2.push_back(4);
	row2.push_back(8);
	row2.push_back(10);
	matrix.push_back(row2);
	vector<int> row3;
	row3.push_back(13);
	row3.push_back(3);
	row3.push_back(6);
	row3.push_back(7);
	matrix.push_back(row3);
	vector<int> row4;
	row4.push_back(15);
	row4.push_back(14);
	row4.push_back(12);
	row4.push_back(16);
	matrix.push_back(row4);
	rotate(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
	while (1);
	return 0;
}

