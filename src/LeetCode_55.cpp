/*
55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

解题思路：对于当前位i，distance表示第i位之前的最远能跳到的位置，如果distance<i，说明怎么也跳不到i,直接return false
          反之，如果distance>=i,更新distance = max(distance,i+nums[i])
		  最后如果i遍历结束，说明可以到达最后一个位置，return true
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

bool canJump(vector<int>& nums) {
	int distance = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (distance < i)
			return false;
		distance = max(distance, i + nums[i]);
	}
	return true;
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	bool result = canJump(nums);
	cout << result << endl;
	while (1);
	return 0;
}
