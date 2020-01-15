/*
47. 全排列 II

给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

#include "iostream"
#include <vector>

using namespace std;

void dfs(int root, vector<int> nums, vector<vector<int>>& result)
{
	if(root == nums.size() - 1)
	{
		result.push_back(nums);
		return;
	}

	for(int i = root; i < nums.size(); i++)
	{
		if(i > root && nums[i] == nums[root])
		{
			continue;
		}
		int temp = nums[i];
		nums[i] = nums[root];
		nums[root] = temp;
		dfs(root + 1, nums, result);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	dfs(0, nums, result);
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	vector<vector<int>> result = permuteUnique(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j];
	}

	return 0;
}
