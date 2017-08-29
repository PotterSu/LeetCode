/*
69. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.

����˼·��1.����
		  ���x����0����1ֱ��ruturn����ͺ�
          ����left�Լ�right�ֱ�Ϊ0��x/2
		  ���left<=right������left��right���м�ֵmid�����mid��ƽ��<=x,mid+1��ƽ������x������mid
		  �������mid*mid<x,˵������ֵӦ����left+1��right֮��
		      ���mid*mid>x,˵������ֵӦ����left��right-1֮��
		  2.ţ��
		  ��ʼ��y(n)�Լ�y(n+1)
		  ��y(n)�Լ�y(n+1)���߲��û��С��һ����ֵ,���ϵ���
		  y(n+1) = (y(n+1)+x/y(n+1))/2
		  y(n) = y(n+1)
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

int mySqrt(int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	long long left = 0;
	long long right = x / 2;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (mid*mid <= x && (mid + 1)*(mid + 1) > x)
		{
			return mid;
		}
		if (mid*mid < x)
			left = mid + 1;
		else{
			right = mid - 1;
		}
	}
}
/*//ţ�ٷ�
int mySqrt(int x) {
if (x == 0)
return 0;
if (x == 1)
return 1;
double y_n_1 =1;
double y_n = 0;
while (abs(y_n - y_n_1) > 0.0001)
{
y_n = y_n_1;
y_n_1 = (y_n_1 + x / y_n_1) / 2;
}
return y_n_1;
}
*/
int main()
{
	int x;
	cin >> x;
	int result = mySqrt(x);
	cout << result << endl;
	while (1);
	return 0;
}
