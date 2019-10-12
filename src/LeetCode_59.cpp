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

����˼·�����ȳ�ʼ��vector
		  Ȼ�������� ���� ���� ���е�˳��1-n*n��������vector�У�ֱ��n*n��������
		  ע����ǣ��������в��꣬now_row+1;
		  �������в��꣬now_col+1
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
	//��ǰ�����������1��ʼ
	int now_num = 1;
	while (now_num <= n*n)
	{
		//����������
		for (int j = now_col; j < n - now_col; j++)
		{
			int i = now_row;
			matrix[i][j] = now_num;
			now_num++;
		}
		//����������
		for (int i = now_row + 1; i < n - now_row; i++)
		{
			int j = n - now_col - 1;
			matrix[i][j] = now_num;
			now_num++;
		}
		//����������
		for (int j = n - now_col - 2; j >= now_col; j--)
		{
			int i = n - now_row - 1;
			matrix[i][j] = now_num;
			now_num++;
		}
		//��ǰ��������������ȫ����now_row+1��Ϊ�´�4�����������׼��
		now_row++;
		//����������
		for (int i = n - now_row - 1; i >= now_row; i--)
		{
			int j = now_col;
			matrix[i][j] = now_num;
			now_num++;
		}
		//��ǰ��������������ȫ����now_col+1��Ϊ�´�4�����������׼��
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

