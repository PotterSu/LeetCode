/*
88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.

����˼·������������λ�����ֱ�Ϊi,j,index��������λnums1��nums2��nums1�ϲ����λ��
          ��nums1��nums2�������ǰ���������ֵ�浽nums1��index��λ�ã�index--
		  ��ʣ�µ�nums1��nums2��Ԫ��ֱ�Ӹ�ֵ��nums1ǰ��Ŀ�λ
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1;
	int j = n - 1;
	int index = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (nums2[j] > nums1[i])
		{
			nums1[index] = nums2[j];
			j--;
			index--;
		}
		else{
			nums1[index] = nums1[i];
			i--;
			index--;
		}
	}
	while (i >= 0)
	{
		nums1[index--] = nums1[i--];
	}
	while (j >= 0)
	{
		nums1[index--] = nums2[j--];
	}

}
int main()
{
	vector<int> nums1;
	nums1.push_back(0);

	int m = 0;
	vector<int> nums2;
	nums2.push_back(1);

	int n = 1;
	merge(nums1, m, nums2, n);
	for (int i = 0; i < nums1.size(); i++)
	{
		cout << nums1[i];
	}
	while (1);
	return 0;
}

