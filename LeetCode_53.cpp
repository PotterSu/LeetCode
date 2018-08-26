/*
53. ��������
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��

����˼·��������a[i]�洢�Ե�i����Ϊ��β��������������У�
          ��ô������Ϊ���������
		  1.���a[i-1]<0,��a[i] = nums[i]
		  2.��֮����a[i] = a[i-1]+nums[i]
		  ����һ�˱����������Եõ���nums[i]��β���������������a[i]
		  ֻ��Ҫ�ҵ�����a[i]�Ϳ���
*/

#include "iostream"
#include "vector"
using namespace std;
int maxSubArray(vector<int>& nums) {
	int *a = new int[nums.size()];
	int maxNum = nums[0];
	a[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (a[i - 1] + nums[i]>nums[i])
			a[i] = a[i - 1] + nums[i];
		else
			a[i] = nums[i];
		if (maxNum < a[i])
			maxNum = a[i];
	}
	delete[]a;
	return maxNum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	cout << maxSubArray(nums) << endl;
	return 0;
}

