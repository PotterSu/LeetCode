/*
16.3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
解题思想：1.首先对输入进行排序
	      2.初步定义一个三个数和（头三个数）ans，并算一下与target的差值diff
		  3.定义一个i,j,k分别记录三个数的位置，对这不断循环遍历，计算三个数的和，
		    如果等于target直接return
			如果与target差值小于当前最小差值diff，更新diff以及ans
			根据sum与target的大小关系更新j,k位置
*/

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int ans = nums[0] + nums[1] + nums[2];
	int diff = abs(ans - target);
	for (int i = 0; i<nums.size(); i++)
	{
		int j = i + 1;
		int k = nums.size() - 1;
		while (j<k)
		{
			int sum = nums[i] + nums[j] + nums[k];
			if (sum == target)
				return sum;
			if (abs(sum - target)<diff)
			{
				diff = abs(sum - target);
				ans = sum;
			}
			if (sum<target)
				j++;
			if (sum>target)
				k--;
		}

	}
	return ans;
}