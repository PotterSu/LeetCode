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

����˼·����distance�洢��ǰλ���Լ�֮ǰ���Ե������Զλ��
          ��endposition��¼��һ����Զ������λ��
		  ���i������endposition���λ�ã���ô���������Ļ���ȻҪ�������Ĵ�������ʱ��Ҫ������һ������������Զendposition�Լ�step++
	      ���i=nums.size()-2��ʱ�򣬾Ϳ��Խ����ˣ����i = endpostion��˵������Ҫ��һ�Σ�������Ȳ���Ҫ������
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

