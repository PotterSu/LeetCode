/*
78. Subsets
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

解题思路：递归回溯
	      trace每层递归的深入，组合的元素个数也在增加
		  从nums的首位开始遍历到最后一位，记录当前位为i，那么以i为头的组合一共有trace(i+1)不同组合
		  对于当前trace递归层，之前的i位组合已经确定，可以压入result中，
		  那么现在只需要确定第i+1位是什么，用for循环从i+1遍历到nums.size()最后每一位都可能选或不选，如果选择某位用path压入该位，trace(i+1)
		  当trace(i+1)结束后说明当前位不选，那么path弹出该位，压入for循环的下一位
		  如此反复，遍历出所有的组合
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void trace(int position, vector<vector<int>> &result, vector<int> nums, vector<int> path)
{
	result.push_back(path);
	for (int i = position; i < nums.size(); i++)
	{
		path.push_back(nums[i]);
		trace(i + 1, result, nums, path);
		path.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result;
	vector<int> path;
	trace(0, result, nums, path);
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int>> result = subsets(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
	}
	while (1);
	return 0;
}

