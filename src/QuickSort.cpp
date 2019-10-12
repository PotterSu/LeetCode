/*
����

����˼·������i=left,j=right�ֱ��ʾa�������������
          ��һ��flag��¼a[left]��
		  ��i<jʱ
		  j��right��ǰ������a[j]>=flag��j--,�������������ʱa[i] = a[j] 
		  i��left��������a[i]<=flag, i++���������������ʱa[j] = a[i]
		  ����i<jʱ��˵����ʱ����flag�Ѿ��ҵ��˺��ʵ�λ��
		  ֱ��a[i] = flag;
		  Ȼ����iΪ�ֽ磬�ֱ��ǰ�������ֽ��еݹ�
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

