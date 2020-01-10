/*
62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？
*/

#include "iostream"
#include "vector"

using namespace std;

int uniquePaths(int m, int n)
{
	if(m == 0 || n == 0)
		return 0;
	vector<vector<int>> a(m);
	for(int i = 0; i < m; i++)
	{
		a[i].resize(n);
	}
	for(int i = 0; i < m; i++)
	{
		a[i][0] = 1;
	}
	for(int j = 0; j < n; j++)
	{
		a[0][j] = 1;
	}
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			a[i][j] = a[i-1][j] + a[i][j-1];
		}
	}

	return a[m-1][n-1];
}


int main()
{
	int result = uniquePaths(7, 3);
	cout << result << endl;

	return 0;
}
