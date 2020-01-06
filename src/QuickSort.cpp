/*
快排
*/

#include "iostream"

using namespace std;

int quicksort(int* a, int left, int right)
{
	if(left < right)
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
		quicksort(a, left, i-1);
		quicksort(a, i+1, right);
	}
}

int main()
{
	int a[11] = { 10, 0, 3, 1, 2, 5, 4, 9, 8, 7, 6 };
	int n = sizeof(a) / sizeof(int);
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}
