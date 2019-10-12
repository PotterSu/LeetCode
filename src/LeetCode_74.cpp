/*
74. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.

解题思路：从matrix右上角与target进行比较，如果右上角值等于target直接返回true，
                                          如果右上角值小于target，行+1
										  如果右上角值大于target，列-1
		  直到target等于当前matrix索引值，或者行加到越界或者列减到越界
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0)
		return false;
	int i = 0;
	int j = matrix[i].size() - 1;
	while (j >= 0 && i < matrix.size())
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] < target)
			i++;
		else if (matrix[i][j] > target)
			j--;
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix;
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(3);
	temp.push_back(5);
	temp.push_back(7);
	matrix.push_back(temp);
	vector<int> temp1;
	temp1.push_back(10);
	temp1.push_back(11);
	temp1.push_back(16);
	temp1.push_back(20);
	matrix.push_back(temp1);
	vector<int> temp2;
	temp2.push_back(23);
	temp2.push_back(30);
	temp2.push_back(34);
	temp2.push_back(50);
	matrix.push_back(temp2);
	int target = 12;
	bool flag = searchMatrix(matrix, target);
	cout << flag << endl;
	return 0;
}
