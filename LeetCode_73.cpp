/*
73. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

����˼·�����þ����һ�к͵�һ������¼��������ĸ��и����Ƿ����0
	      ���ȿ���һ�к͵�һ���Ƿ���0
		  Ȼ��ӣ�1��1������m,n�����μ�飬��0�ͶԵ�һ�л��һ�����¸�ֵ
		  Ȼ��ӵڶ��еڶ��п�ʼ�����ݵ�һ�С���һ���Ƿ�Ϊ0�����ֵ0
		  ���ֵ��һ�С���һ��
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
	//��¼��һ�� ��һ���Ƿ���0��״̬
	int flag_col = 0;
	int flag_row = 0;
	//������һ�� ��һ�У��������״̬
	for (int i = 0; i < m; i++)
		if (matrix[i][0] == 0)
			flag_col = 1;
	for (int j = 0; j < n; j++)
		if (matrix[0][j] == 0)
			flag_row = 1;
	//�õ�һ�� ��һ�м�¼��������ĸ��и��е�0���
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
		if (matrix[i][j] == 0)
		{
			matrix[i][0] = 0;
			matrix[0][j] = 0;
		}
		}
	//���¾���
	for (int j = 1; j < n; j++)
		if (matrix[0][j] == 0)
			for (int i = 0; i < m; i++)
				matrix[i][j] = 0;
	for (int i = 1; i < m; i++)
		if (matrix[i][0] == 0)
			for (int j = 1; j < n; j++)
				matrix[i][j] = 0;
	//�����µ�һ�� ��һ�����
	if (flag_col)
		for (int i = 0; i < m; i++)
			matrix[i][0] = 0;
	if (flag_row)
		for (int j = 0; j < n; j++)
			matrix[0][j] = 0;
	//���
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