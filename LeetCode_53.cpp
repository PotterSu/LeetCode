/*
53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大为 6。

解题思路：用数组a[i]存储以第i个数为结尾的最大连续子序列，
          那么这样分为两种情况：
		  1.如果a[i-1]<0,则a[i] = nums[i]
		  2.反之，则a[i] = a[i-1]+nums[i]
		  这样一趟遍历下来可以得到以nums[i]结尾的最大连续子序列a[i]
		  只需要找到最大的a[i]就可以
*/

#include "iostream"
#include "vector"
using namespace std;
int maxSubArray(vector<int>& nums) {
	int *a = new int[nums.size()];
	int maxNum = nums[0];
	a[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (a[i - 1] + nums[i]>nums[i])
			a[i] = a[i - 1] + nums[i];
		else
			a[i] = nums[i];
		if (maxNum < a[i])
			maxNum = a[i];
	}
	delete[]a;
	return maxNum;
}

int _tmain(int argc, _TCHAR* argv[])
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

