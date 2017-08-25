/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1]
]

解题思路：整体思路与Permutations相同，唯一需要考虑的是重复的问题
          用递归回溯来做（dfs）
		  首先对nums进行排序！
          对于给定的nums向量有n位数，r从0开始向n-1移动表示当前第r位可以取哪些数字的情况，
		  （显然r=0时，如果没有重复的元素可以取n个数，r=1时可以取n-1个数，因为第0位已经确定）通过for循环，分别将i=r+1到n-1的数字与第r位数字调换
		  注意：如果一旦碰到nums[i]==nums[r]，直接跳过，不进行调换，调换的话会出现重复情况！！！
		  那么有了第r位的情况，通过dfs(r+1,n,nums，result)递归表示后续位组合的情况，
		  一旦r与n-1相等，说明到了最后一位，前面都已经排好，可以直接存储nums。
		  然后递归反向回溯直至所有的nums情况都被存储
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;
void dfs(int r, int n, vector<int> nums, vector<vector<int>> &result)
{
	if (r == n - 1)
	{
		result.push_back(nums);
		return;
	}
	dfs(r + 1, n, nums, result);
	for (int i = r + 1; i < n; i++)
	{
		if (nums[i] == nums[r])
			continue;
		int temp = nums[r];
		nums[r] = nums[i];
		nums[i] = temp;
		dfs(r + 1, n, nums, result);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	dfs(0, nums.size(), nums, result);
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
	while (1);
	return 0;
}

