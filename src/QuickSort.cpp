/*
快排

解题思路：设置i=left,j=right分别表示a数组的左右两端
          立一个flag记录a[left]，
		  当i<j时
		  j从right向前遍历，a[j]>=flag，j--,当不满足该条件时a[i] = a[j] 
		  i从left向后遍历，a[i]<=flag, i++，当不满足该条件时a[j] = a[i]
		  跳出i<j时，说明此时对于flag已经找到了合适的位置
		  直接a[i] = flag;
		  然后以i为分界，分别对前后两部分进行递归
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void quicksort(int a[], int left, int right)
{
	if (left < right)
	{
		cout << "left" << left << endl;
		cout << "right" << right << endl;
		int i = left;
		int j = right;
		int flag = a[left];//0
		while (i < j)
		{
			while (i<j&&a[j] >= flag)
			{
				j--;
			}
			a[i] = a[j];
			while (i<j&&a[i] <= flag)
			{
				i++;
			}
			a[j] = a[i];
		}
		a[j] = flag;
		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);
	}
}

int main()
{
	int a[10] = { 0, 3, 1, 2, 5, 4, 9, 8, 7, 6 };
	int n = sizeof(a) / sizeof(int);
	cout << n - 1;
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	while (1);
	return 0;
}

