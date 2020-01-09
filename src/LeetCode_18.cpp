/*
18.四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
#include "iostream"
#include "vector"

using namespace std;
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
// 	vector<vector<int>>result;
// 	if (nums.size()<4)
// 		return result;
// 	sort(nums.begin(), nums.end());
// 	for (int i = 0; i < nums.size() - 3; i++)
// 	{
// 		if (i>0 && nums[i] == nums[i - 1])
// 			continue;
// 		for (int j = i + 1; j < nums.size() - 2; j++)
// 		{
// 			if (j>i + 1 && nums[j] == nums[j - 1])
// 				continue;
// 			int left = j + 1;
// 			int right = nums.size() - 1;
// 			while (left < right)
// 			{
// 				if (left > j + 1 && nums[left] == nums[left - 1])
// 				{
// 					left++;
// 					continue;
// 				}
// 				if (right < nums.size() - 1 && nums[right] == nums[right + 1])
// 				{
// 					right--;
// 					continue;
// 				}
// 				int sum = nums[i] + nums[j] + nums[left] + nums[right];
// 				if (target == sum)
// 				{
// 					vector<int> temp;
// 					temp.push_back(nums[i]);
// 					temp.push_back(nums[j]);
// 					temp.push_back(nums[left]);
// 					temp.push_back(nums[right]);
// 					result.push_back(temp);
// 					left++;
// 					right--;
// 				}
// 				if (sum < target)
// 					left++;
// 				if (sum > target)
// 					right--;
//
// 			}
//
// 		}
//
// 	}
// 	return result;
// }

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	if(nums.size() < 4)
	{
		return result;
	}
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size() - 3; i++)
	{
		if(i > 0 && nums[i] == nums[i - 1])
			continue;
		int a = nums[i];
		for(int j = i + 1; j < nums.size() - 2; j++)
		{
			if((j > i + 1) && nums[j] == nums[j-1])
				continue;
			int b = nums[j];
			int left = j + 1;
			int right = nums.size() - 1;
			while(left < right)
			{
				if((left > j + 1) && nums[left] == nums[left - 1])
				{
					left++;
					continue;
				}
				if(right < nums.size() - 1 && nums[right + 1] == nums[right])
				{
					right--;
					continue;
				}
				if(a + b + nums[left] + nums[right] < target)
				{
					left++;
					continue;
				}
				if(a + b + nums[left] + nums[right] > target)
				{
					right--;
					continue;
				}
				if(a + b + nums[left] + nums[right] == target)
				{
					vector<int> temp;
					temp.push_back(a);
					temp.push_back(b);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					result.push_back(temp);
					left++;
					right--;
				}
			}
		}
	}
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(-3);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	int target = 1;
	vector<vector<int>>result = fourSum(nums, target);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
