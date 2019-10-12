
/*
81. Search in Rotated Sorted Array II
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

����˼·������˼��
          �����ҵ�middle,���nums[middle]����targetֱ��return true
		                 ���nums[middle]����nums[left]˵��left-middle֮���������ʱ���target��left-middle֮�䣬right=middle-1����֮left=middle+1
						 ���nums[middle]С��nums[left]˵��middle-right֮���������ʱ���target��middle-right֮�䣬left = middle+1����֮right=middle-1
						 ���nums[middle]��nums[left]��ȣ��������ظ��ģ�left-middle֮�䶼��һ���ģ���ʱ����Ҫ��left++��ֱ����һ���ٽ��ж���
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

