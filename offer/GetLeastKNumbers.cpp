/*
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，
则最小的4个数字是1,2,3,4,。
*/

#include "iostream"
#include <vector>

using namespace std;

//3,2,3,6,7,2,3,6,3,4,3
void QuickSort(vector<int> a, vector<int>& result, int left, int right, int k)
{
	if(result.size() == k)
		return;
	if(left <= right)
	{
		int i = left;
		int j = right;
		int flag = a[left];
		while(i < j)
		{
			while(i < j && a[j] >= flag)
			{
				j--;
			}
			a[i] = a[j];
			while(i < j && a[i] <= flag)
			{
				i++;
			}
			a[j] = a[i];
		}
		a[j] = flag;
		if(j <= k)
			result.push_back(flag);
		QuickSort(a, result, left, i-1, k);
		QuickSort(a, result, i+1, right, k);
	}
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> result;
	if(input.size() == 0 || k == 0 || input.size() < k)
		return result;

	QuickSort(input, result, 0, input.size() - 1, k);
	return result;
}

int main()
{
	vector<int> numbers = {2, 1, 4, 10, 9, 8, 7, 11};
	vector<int> result = GetLeastNumbers_Solution(numbers, 4);
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}
