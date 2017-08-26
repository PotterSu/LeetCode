/*
40. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
解题思想：这道题与39题一样，递归回溯，唯一不同之处在于同一数字不能重复使用，并且candidates中可能出现重复数字，所以要判断避免重复的问题
          首先对candidates排序
          用r记录当前位candidates遍历到的位置，不断循环i=r到candidates.size()，如果i!=r并且candidates[i]与candidates[i-1]相等，则直接continue，这样避免重复
		  一旦发现之前temp记录的总和sum+candidates[i]与target相等，将temp加入result中，return
		  如果sum<target，将candidates[i]加入temp中，继续递归dfs(i+1, candidates.size(), candidates, sum, target, result, temp);
		  temp.pop_back()，这是因为当前位的情况都已遍历完，需要将当前位弹出，为压入后一位
		  如果sum>target,直接return
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void dfs(int r, vector<int> candidates, int sum, int target, vector<vector<int>> &result, vector<int> temp)
{
	//111335
	for (int i = r; i < candidates.size(); i++)
	{
		if (i != r&&candidates[i] == candidates[i - 1])
			continue;
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
			dfs(i + 1, candidates, sum, target, result, temp);
			temp.pop_back();
			sum = sum - candidates[i];
		}
		if (sum > target)
		{
			return;
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> temp;
	int sum = 0;
	dfs(0, candidates, sum, target, result, temp);
	return result;

}

int main()
{
	vector<int> candidates;
	candidates.push_back(3);
	candidates.push_back(1);
	candidates.push_back(3);
	candidates.push_back(5);
	candidates.push_back(1);
	candidates.push_back(1);
	int target = 8;

	vector<vector<int>> result = combinationSum2(candidates, target);
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
