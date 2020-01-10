/*
63.不同路径 II
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
*/

#include "iostream"
#include "vector"

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	if(obstacleGrid.size() == 0)
		return 0;
	if(obstacleGrid[0].size() == 0)
		return 0;
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if(obstacleGrid[0][0] == 1)
		return 0;

	long dp[m][n];
	for(int i = 0; i < m; i++)
	{
		if(i == 0)
		{
			dp[i][0] = 1;
			continue;
		}
		if(obstacleGrid[i][0] == 1)
		{
			dp[i][0] = 0;
			continue;
		}
		if(i > 0)
		{
			dp[i][0] = dp[i - 1][0];
		}
	}
	for(int j = 0; j < n; j++)
	{
		if(j == 0)
		{
			dp[0][j] = 1;
			continue;
		}
		if(obstacleGrid[0][j] == 1)
		{
			dp[0][j] = 0;
			continue;
		}
		if(j > 0)
		{
			dp[0][j] = dp[0][j - 1];
		}
	}
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(obstacleGrid[i][j] == 1)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[m - 1][n - 1];
}

int main()
{
	int m = 3;
	int n = 3;
	vector<vector<int>> a(m);
	for(int i = 0; i < m; i++)
	{
		a.resize(n);
	}
	a[0] = {0, 0, 0};
	a[1] = {0, 1, 0};
	a[2] = {0, 0, 0};

	int result = uniquePathsWithObstacles(a);
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < a[0].size(); j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << result << endl;

	return 0;
}
