/*
48. 旋转图像

给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

#include "iostream"
#include "vector"

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	//对角线调换
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	//左右翻转
	for(int i = 0; i < matrix.size(); i++)
	{
		for(int j = 0; j < matrix[i].size() / 2; j++)
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
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
