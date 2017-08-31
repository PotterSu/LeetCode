/*
52. N-Queens II
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

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

解题思路：1.用row存储当前行中已有棋子的列id，用col存储当前j列是否有棋子，有为1,无为0
          2.对于当前第r行，我们首先判断是否已经到达最后一行，如果已经到最后一行，说明该方案可行，count+1
		  3.如果没到最后一行:
		    我们要在该行放一个棋子（前r-1行每行都有棋子）
		    那么需要遍历该行的所有列，看与之前r-1行的棋子是否冲突，如果当前列有冲突，试着在下一列放置棋子
		    如果都没有冲突，那么将该行的row以及col设置，进行下一行的递归
            如果遍历了所有列都有冲突，说明之前r-1行的Q放置方案有问题，需要回溯，重置col、row为0
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

int dfs(int r, int n, int count, int row[], int col[])
{
	if (r == n)
	{
		count++;
	}
	int i, j;
	for (j = 0; j < n; j++)
	{
		if (col[j] == 0)
		{
			for (i = 0; i < r; i++)
				if (abs(i - r) == abs(row[i] - j))
					break;
			if (i == r)
			{
				col[j] = 1;
				row[r] = j;
				count = dfs(r + 1, n, count, row, col);
				col[j] = 0;
				row[r] = 0;
			}
		}
	}
	return count;
}

int totalNQueens(int n) {
	int count = 0;
	int row[1000];
	memset(row, 0, 1000 * sizeof(int));
	int col[1000];
	memset(col, 0, 1000 * sizeof(int));
	count = dfs(0, n, count, row, col);
	return count;
}

int main()
{
	int result = 0;
	result = totalNQueens(4);
	cout << result << endl;
	while (1);
	return 0;
}

