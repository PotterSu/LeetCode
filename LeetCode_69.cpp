/*
69. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.

解题思路：1.二分
		  如果x等于0或者1直接ruturn结果就好
          设置left以及right分别为0，x/2
		  如果left<=right，计算left与right的中间值mid，如果mid的平方<=x,mid+1的平方大于x，返回mid
		  否则如果mid*mid<x,说明返回值应该在left+1和right之间
		      如果mid*mid>x,说明返回值应该在left和right-1之间
		  2.牛顿
		  初始化y(n)以及y(n+1)
		  当y(n)以及y(n+1)两者差距没有小于一定阈值,不断迭代
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
/*//牛顿法
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
