/*
39.Combination Sum

Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]
解题思想：递归回溯
          首先对candidates排序
          用r记录当前位，不断循环r到candidates.size()，一旦发现之前temp记录的总和sum+candidates[i]与target相等，将temp加入result中，return
		  如果sum<target，将candidates[i]加入temp中，递归dfs(i, candidates.size(), candidates, sum, target, result, temp);
		  temp.pop_back()，这是因为当前位的情况都已遍历完，需要将当前位弹出，为压入后一位
		  如果sum>target,直接return
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void dfs(int r, int n, vector<int> candidates, int sum, int target, vector<vector<int>> &result, vector<int> temp)
{
	for (int i = r; i < candidates.size(); i++)
	{
		sum = sum + candidates[i];
		if (sum == target)
		{
			temp.push_back(candidates[i]);
			result.push_back(temp);
			return;
		}
		if (sum < target)
		{
			temp.push_back(candidates[i]);
			dfs(i, candidates.size(), candidates, sum, target, result, temp);
			temp.pop_back();
			sum = sum - candidates[i];
		}
		if (sum > target)
		{
			return;
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> temp;
	int sum = 0;
	dfs(0, candidates.size(), candidates, sum, target, result, temp);
	return result;

}

int main()
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	int target = 7;
	vector<vector<int>> result = combinationSum(candidates, target);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
	}
	while (1);
	return 0;
}

