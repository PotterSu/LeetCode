/*
77. Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]

解题思路：递归回溯
	      用position记录当前组合k位中的第几位，那么该位最多到n个数中的第n - k + position的位置，后面无法继续递归。如position=1,那么最多到3，如果到4将组不成2位数
		  用一个temp的向量添加当前position位,然后backtrace到下一个position,继续添加
		  如果position等于k+1了，说明这是一个符合条件，将temp添加到最终结果result中，反之继续backtrace
		  直到遍历所有的情况

	注意：每次返回更新当前postion位时，需要将temp上一次压入的当前postion位进行弹出，要不会滞留
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void backtrace(vector<vector<int>> &result, vector<int> temp, int jj, int position, int n, int k)
{
	if (position == k + 1)
	{
		result.push_back(temp);
		return;
	}

	for (int j = jj; j <= n - k + position; j++)
	{
		temp.push_back(j);
		backtrace(result, temp, j + 1, position + 1, n, k);
		temp.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> result;
	if (n < k)
	{
		return result;
	}
	vector<int> temp;
	for (int i = 1; i <= n - k + 1; i++)
	{
		temp.push_back(i);
		backtrace(result, temp, i + 1, 2, n, k);
		temp.pop_back();
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<vector<int>> result = combine(n, k);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
	}
	while (1);
	return 0;
}

