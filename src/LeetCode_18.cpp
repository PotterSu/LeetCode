/*
18.4Sum

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]

解题思想：1.首先对输入进行排序
		  2.定义一个i,j,left，right分别记录四个数的位置，对这不断循环遍历，计算四个数的和，
		    如果等于target直接存入result向量中
			如果不相等根据sum与target的大小关系更新right,left位置
			避免重复：每层循环判断i，j,left是否与前一个相等，right是否与后一个相等，如果相等直接continue

思想与3sum相似，整体大致相同，要注意避免重复的问题
*/
#include "stdafx.h"
#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>>result;
	if (nums.size()<4)
		return result;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 3; i++)
	{
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < nums.size() - 2; j++)
		{
			if (j>i + 1 && nums[j] == nums[j - 1])
				continue;
			int left = j + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				if (left > j + 1 && nums[left] == nums[left - 1])
				{
					left++;
					continue;
				}
				if (right < nums.size() - 1 && nums[right] == nums[right + 1])
				{
					right--;
					continue;
				}
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (target == sum)
				{
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					result.push_back(temp);
					left++;
					right--;
				}
				if (sum < target)
					left++;
				if (sum > target)
					right--;

			}

		}

	}
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	int target = 0;
	vector<vector<int>>result = fourSum(nums, target);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}

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