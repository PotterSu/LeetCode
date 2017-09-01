/*
90. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]

解题思路：解题思路与subset一致，唯一不同的是要处理重复问题
          对于当前递归层，如果i>r并且nums[i] == nums[i-1]，直接continue，path不增加nums[i]，因为加的也是重复的
		  对于下一个递归层，也是一样，对于i=r如果与r-1重复可以加入path，但是对于当i>r时重复的话则不能压入path

*/

void dfs(int r, vector<vector<int>> &result, vector<int> nums, vector<int> path)
{
	result.push_back(path);
	for (int i = r; i < nums.size(); i++)
	{
		if (i > r && nums[i] == nums[i - 1])
			continue;
		path.push_back(nums[i]);
		dfs(i + 1, result, nums, path);
		path.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	vector<int> path;
	dfs(0, result, nums, path);
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	vector<vector<int>> result = subsetsWithDup(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
	}
	while (1);
	return 0;
}

