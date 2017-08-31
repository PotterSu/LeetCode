/*
35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 �� 2
[1,3,5,6], 2 �� 1
[1,3,5,6], 7 �� 4
[1,3,5,6], 0 �� 0

����˼�룺��nums����λ��ʼ����������nums�Ѿ��ź�˳������һ�����ִ��ڵ���target�����Ϸ��ص�ǰλ����Ϊ���ս��
          ��������һλ��û�з��أ�˵��nums����������targetС����ôֻ�践��nums.size()����
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

