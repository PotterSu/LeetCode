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

����˼·��1.��row�洢��ǰ�����������ӵ���id����col�洢��ǰj���Ƿ������ӣ���Ϊ1,��Ϊ0
          2.���ڵ�ǰ��r�У����������ж��Ƿ��Ѿ��������һ�У�����Ѿ������һ�У�˵���÷������У�count+1
		  3.���û�����һ��:
		    ����Ҫ�ڸ��з�һ�����ӣ�ǰr-1��ÿ�ж������ӣ�
		    ��ô��Ҫ�������е������У�����֮ǰr-1�е������Ƿ��ͻ�������ǰ���г�ͻ����������һ�з�������
		    �����û�г�ͻ����ô�����е�row�Լ�col���ã�������һ�еĵݹ�
            ��������������ж��г�ͻ��˵��֮ǰr-1�е�Q���÷��������⣬��Ҫ���ݣ�����col��rowΪ0
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

