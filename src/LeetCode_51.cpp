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

����˼·��1.��row�洢��ǰ��������Q����id����col�洢��ǰj���Ƿ���Q����Ϊ1,��Ϊ0
          2.���ڵ�ǰ��r�У����������ж��Ƿ��Ѿ��������һ�У�����Ѿ������һ�У�˵���÷������У���result���д洢
		  3.���û�����һ��:
		    ����Ҫ�ڸ��з�һ��Q��ǰr-1��ÿ�ж���Q��
		    ��ô��Ҫ�������е������У�����֮ǰr-1�е�Q�Ƿ��ͻ�������ǰ���г�ͻ����������һ�з���Q
		    �����û�г�ͻ����ô�����е�row�Լ�col���ã�������һ�еĵݹ�
            ��������������ж��г�ͻ��˵��֮ǰr-1�е�Q���÷��������⣬��Ҫ����
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

