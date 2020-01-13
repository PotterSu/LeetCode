/*
64. 最小路径和
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

#include "iostream"
#include "vector"

using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
	if(grid.size() == 0)
		return 0;
	if(grid[0].size() == 0)
		return 0;
	int m = grid.size();
	int n = grid[0].size();

	int a[m][n];
	for(int i = 0; i < m; i++)
	{
		if(i > 0)
		{
			a[i][0] = a[i-1][0] + grid[i][0];
		}
		else
		{
			a[i][0] = grid[i][0];
		}
	}
	for(int j = 0; j < n; j++)
	{
		if(j > 0)
		{
			a[0][j] = a[0][j-1] + grid[0][j];
		}
		else
		{
			a[0][j] = grid[0][j];
		}
	}
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			a[i][j] = (a[i-1][j]<=a[i][j-1]?a[i-1][j]:a[i][j-1]) + grid[i][j];
		}
	}
	return a[m-1][n-1];
}

int main()
{
	int m = 3;
	int n = 3;
	vector<vector<int>> a(m);
	for(int i = 0; i < m; i++)
	{
		a[i].resize(n);
	}
	a[0] = {1, 3, 1};
	a[1] = {1, 5, 1};
	a[2] = {4, 2, 1};

	int result = minPathSum(a);

	cout << result << endl;

	return 0;
}
