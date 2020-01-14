/*
46. 全排列

给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include "iostream"
#include "vector"
#include "stack"

using namespace std;

void dfs(int root, vector<int> nums, vector<vector<int>>& result)
{
	if(root == nums.size() - 1)
	{
		result.push_back(nums);
	}
	for(int i = root; i < nums.size(); i++)
	{
		int temp = nums[i];
		nums[i] = nums[root];
		nums[root] = temp;
		dfs(root + 1, nums, result);
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> result;
	dfs(0, nums, result);
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int>> result = permute(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j];
	}
	return 0;
}
