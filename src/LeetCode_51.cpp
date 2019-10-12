/*
51. N-Queens
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]

解题思路：1.用row存储当前行中已有Q的列id，用col存储当前j列是否有Q，有为1,无为0
          2.对于当前第r行，我们首先判断是否已经到达最后一行，如果已经到最后一行，说明该方案可行，用result进行存储
		  3.如果没到最后一行:
		    我们要在该行放一个Q（前r-1行每行都有Q）
		    那么需要遍历该行的所有列，看与之前r-1行的Q是否冲突，如果当前列有冲突，试着在下一列放置Q
		    如果都没有冲突，那么将该行的row以及col设置，进行下一行的递归
            如果遍历了所有列都有冲突，说明之前r-1行的Q放置方案有问题，需要回溯
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void dfs(int r, int n, int row[], int col[], vector<vector<string>> &result)
{
	int i, j;
	if (r == n)
	{
		vector<string>go;
		for (i = 0; i<n; ++i)
		{
			string temp(n, '.');
			temp[row[i]] = 'Q';
			go.push_back(temp);
		}
		result.push_back(go);
	}
	for (i = 0; i<n; ++i)
	{
		if (col[i] == 0)
		{
			for (j = 0; j<r; ++j)
				if (abs(j - r) == abs(i - row[j]))break;
			if (j == r)
			{
				row[r] = i;
				col[i] = 1;
				dfs(r + 1, n, row, col, result);
				col[i] = 0;
				row[r] = 0;
			}
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> result;
	int row[1000];
	int col[1000];
	memset(row, 0, 1000 * sizeof(int));
	memset(col, 0, 1000 * sizeof(int));
	dfs(0, n, row, col, result);
	return result;
}


int main()
{
	int n;
	cin >> n;
	vector<vector<string>> result = solveNQueens(n);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
		}
	}
	while (1);
	return 0;
}

