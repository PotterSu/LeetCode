/*
55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

����˼·�����ڵ�ǰλi��distance��ʾ��iλ֮ǰ����Զ��������λ�ã����distance<i��˵����ôҲ������i,ֱ��return false
          ��֮�����distance>=i,����distance = max(distance,i+nums[i])
		  ������i����������˵�����Ե������һ��λ�ã�return true
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
