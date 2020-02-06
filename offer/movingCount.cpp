/*
地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
#include "iostream"
#include <vector>

using namespace std;

int getSum(int num)
{
	int result = 0;
	while(num > 0)
	{
		result += num % 10;
		num /= 10;
	}
	return result;
}

int search(int threshold, int rows, int cols, int row, int col, vector<vector<int>>& m)
{
	if(row >= 0 && row < rows && col >= 0 && col < cols &&
	   m[row][col] == 0 && (getSum(row) + getSum(col) <= threshold))
	{
		m[row][col] = 1;
		int count_left = search(threshold, rows, cols, row, col-1, m);
		int count_right = search(threshold, rows, cols, row, col+1, m);
		int count_top = search(threshold, rows, cols, row-1, col, m);
		int count_bottom = search(threshold, rows, cols, row+1, col, m);

		return 1 + count_left + count_right + count_top + count_bottom;
	}
	return 0;
}

int movingCount(int threshold, int rows, int cols)
{
	if(threshold < 0 || rows <= 0 || cols <= 0)
		return 0;
	vector<vector<int>> m(rows);
	for(int i = 0; i < rows; i++)
	{
		m[i].resize(cols);
	}
	int count = search(threshold, rows, cols, 0, 0, m);
	return count;
}

int main()
{
	int result = movingCount(18, 100, 100);
	cout << result << endl;

	return 0;
}
