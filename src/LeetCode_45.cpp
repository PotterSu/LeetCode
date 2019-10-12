/*
45. Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

解题思路：用distance存储当前位置以及之前可以到达的最远位置
          用endposition记录下一次最远能跳的位置
		  如果i遍历到endposition这个位置，那么再往下跳的话定然要增加跳的次数，此时需要更新下一次能跳到的最远endposition以及step++
	      最后当i=nums.size()-2的时候，就可以结束了，如果i = endpostion，说明还需要跳一次，如果不等不需要再跳了
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

int jump(vector<int>& nums) {
	int distance = 0;
	int endposition = 0;
	int step = 0;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		distance = max(distance, i + nums[i]);
		if (endposition == i)
		{
			endposition = distance;
			step++;
		}
	}
	return step;
}

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	int minest = jump(nums);
	cout << minest << endl;
	while (1);
	return 0;
}

