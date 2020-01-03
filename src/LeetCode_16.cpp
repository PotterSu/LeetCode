/*
16. 最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stack"

using namespace std;

// int threeSumClosest(vector<int>& nums, int target) {
// 	sort(nums.begin(), nums.end());
// 	int ans = nums[0] + nums[1] + nums[2];
// 	int diff = abs(ans - target);
// 	for (int i = 0; i<nums.size(); i++)
// 	{
// 		int j = i + 1;
// 		int k = nums.size() - 1;
// 		while (j<k)
// 		{
// 			int sum = nums[i] + nums[j] + nums[k];
// 			if (sum == target)
// 				return sum;
// 			if (abs(sum - target)<diff)
// 			{
// 				diff = abs(sum - target);
// 				ans = sum;
// 			}
// 			if (sum<target)
// 				j++;
// 			if (sum>target)
// 				k--;
// 		}
//
// 	}
// 	return ans;
// }

int threeSumClosest(vector<int>& nums, int target)
{
	if(nums.size() <= 2)
		return 0;
	//排序
	sort(nums.begin(), nums.end());

	int diff = abs(nums[0] + nums[1] + nums[2] - target);
	int result = nums[0] + nums[1] + nums[2];
	for(int i = 0; i < nums.size(); i++)
	{
		int left = i + 1;
		int right = nums.size() - 1;
		while(left < right)
		{
			if(nums[i] + nums[left] + nums[right] == target)
			{
				return target;
			}
			else
			{
				if(abs(nums[i] + nums[left] + nums[right] - target) < diff)
				{
					diff = abs(nums[i] + nums[left] + nums[right] - target);
					result = nums[i] + nums[left] + nums[right];
				}
				if(nums[i] + nums[left] + nums[right] < target)
				{
					left++;
				}
				if(nums[i] + nums[left] + nums[right] > target)
				{
					right--;
				}
			}
		}
	}
	return result;
}

int main()
{
	vector<int> v;
	v.push_back(-1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-4);
	int result = threeSumClosest(v, 1);
	cout << result << endl;

	return 0;
}
