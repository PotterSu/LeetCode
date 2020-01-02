/*
15. 三数之和
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stack"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	if(nums.size() < 3)
	{
		return res;
	}
	for(int i = 0; i < nums.size() - 2; i++)
	{
		if(nums[i] > 0)
			return res;
		if(i > 0 && nums[i] == nums[i - 1])
			continue;

		int l = i + 1;
		int r = nums.size() - 1;
		while(l < r)
		{
			if(nums[i] + nums[l] + nums[r] == 0)
			{
				vector<int> temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[l]);
				temp.push_back(nums[r]);
				res.push_back(temp);
				while(l < r && nums[l] == nums[l + 1])
				{
					l++;
				}
				while(l < r && nums[r] == nums[r - 1])
				{
					r--;
				}
				l++;
				r--;
				continue;
			}
			if(nums[i] + nums[l] + nums[r] < 0)
			{
				l++;
			}
			if(nums[i] + nums[l] + nums[r] > 0)
			{
				r--;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> v;
	v.push_back(-1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(-1);
	v.push_back(-4);
	vector<vector<int>> result = threeSum(v);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
