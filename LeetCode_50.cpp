/*
50.Pow(x, n)

Implement pow(x, n)

解题思路：如果n = 0,直接返回1
          因为n可能很大，所以要开一个long long类型的p存n
		  如果p<0，x=1/x，p = -p;
		  接下来每次以n/2的增量进行连乘
		  最终返回结果
要考虑n<0，n很大,以及O(n)超时的问题，所以用二分来做
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

double myPow(double x, int n) {
	if (n == 0)
		return 1;
	long long p = n;
	if (p < 0)
	{
		x = 1 / x;
		p = -p;
	}
	int half = p / 2;
	double result;
	if (p % 2 == 0)
	{
		result = myPow(x*x, half);
	}
	if (p % 2 != 0)
	{
		result = myPow(x*x, half);
		result = x*result;
	}

	return result;
}


int main()
{
	double x;
	int n;
	cin >> x;
	cin >> n;
	double result = myPow(x, n);
	cout << result << endl;
	while (1);
	return 0;
}

