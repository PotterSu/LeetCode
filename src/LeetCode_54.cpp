/*
54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

����˼·��1.����up,down,left,right��ʾ��ǰ���������ĵ�ǰ����
            ��������ұ�����ĳ�У�up++;������ϵ��±�����ĳ��right--;������ҵ��������ĳ��down--;������µ��ϱ�����ĳ��left++
		  2.ֱ��left>right����up>down��break,return
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> temp;
	if (matrix.size() == 0)
		return temp;
	int up = 0;
	int right = matrix[0].size() - 1;
	int left = 0;
	int down = matrix.size() - 1;
	while (true)
	{
		if (left > right)
			break;
		for (int j = left; j <= right; j++)
		{
			temp.push_back(matrix[up][j]);
		}
		up++;
		if (up > down)
			break;
		for (int i = up; i <= down; i++)
		{
			temp.push_back(matrix[i][right]);
		}
		right--;
		if (right < left)
			break;
		for (int j = right; j >= left; j--)
		{
			temp.push_back(matrix[down][j]);
		}
		down--;
		if (down < up)
			break;
		for (int i = down; i >= up; i--)
		{
			temp.push_back(matrix[i][left]);
		}
		left++;
	}
	return temp;
}

int main()
{
	vector<vector<int>> matrix;
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);
	matrix.push_back(temp);
	vector<int> temp1;
	temp1.push_back(5);
	temp1.push_back(6);
	temp1.push_back(7);
	temp1.push_back(8);
	matrix.push_back(temp1);
	vector<int> temp2;
	temp2.push_back(9);
	temp2.push_back(10);
	temp2.push_back(11);
	temp2.push_back(12);
	matrix.push_back(temp2);
	vector<int> temp3;
	temp3.push_back(13);
	temp3.push_back(14);
	temp3.push_back(15);
	temp3.push_back(16);
	matrix.push_back(temp3);
	vector<int> result = spiralOrder(matrix);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	while (1);
	return 0;
}

