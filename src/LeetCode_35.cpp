/*
35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

解题思想：从nums的首位开始遍历，由于nums已经排好顺序，所以一旦发现大于等于target，马上返回当前位置作为最终结果
          如果到最后一位都没有返回，说明nums所有数都比target小，那么只需返回nums.size()即可
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int i;
	for (i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= target)
		{
			return i;
		}
	}
	if (i == nums.size())
		return i;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	int target = 7;
	int position = searchInsert(nums, target);
	cout << position << endl;
	while (1);
	return 0;
}

