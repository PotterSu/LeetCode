
/*
81. Search in Rotated Sorted Array II
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

解题思路：二分思想
          首先找到middle,如果nums[middle]等于target直接return true
		                 如果nums[middle]大于nums[left]说明left-middle之间递增，此时如果target在left-middle之间，right=middle-1；反之left=middle+1
						 如果nums[middle]小于nums[left]说明middle-right之间递增，此时如果target在middle-right之间，left = middle+1；反之right=middle-1
						 如果nums[middle]与nums[left]相等，表明有重复的，left-middle之间都是一样的，这时候需要将left++，直到不一样再进行二分
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

bool search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (nums[middle] == target)
			return true;
		else if (nums[middle] > nums[left])
		{
			if (target >= nums[left] && target < nums[middle])
				right = middle - 1;
			else
				left = middle + 1;
		}
		else if (nums[middle] < nums[left])
		{
			if (target>nums[middle] && target <= nums[right])
				left = middle + 1;
			else
				right = middle - 1;
		}
		else
		{
			left++;
		}

	}
	return false;
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	bool position = search(nums, 5);
	cout << position << endl;
	while (1);
	return 0;
}

