/*
75. Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

解题思路：首先遍历一遍记下0 1 2出现的个数
          然后按照0 1 2的个数重新对nums按照0 1 2的顺序赋值
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void sortColors(vector<int>& nums) {
	int count_0 = 0;
	int count_1 = 0;
	int count_2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			count_0++;
		if (nums[i] == 1)
			count_1++;
		if (nums[i] == 2)
			count_2++;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (count_0 > 0)
		{
			nums[i] = 0;
			count_0--;
			continue;
		}
		if (count_1 > 0)
		{
			nums[i] = 1;
			count_1--;
			continue;
		}
		if (count_2 > 0)
		{
			nums[i] = 2;
			count_2--;
			continue;
		}
	}
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(2);
	sortColors(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	while (1);
	return 0;
}