/*
53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

*/

#include "iostream"
#include "vector"
using namespace std;

int maxSubArray(vector<int>& nums)
{
	if(nums.size() == 0)
	{
		return 0;
	}
	if(nums.size() == 1)
	{
		return nums[0];
	}
	int maxNum = nums[0];
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	for(int i = 1; i < nums.size(); i++)
	{
		if(nums[i] + dp[i-1] > nums[i])
		{
			dp[i] = dp[i - 1] + nums[i];
		}
		else
		{
			dp[i] = nums[i];
		}
		if(dp[i] > maxNum)
		{
			maxNum = dp[i];
		}
	}
	return maxNum;
}

int main()
{
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	cout << maxSubArray(nums) << endl;
	return 0;
}
