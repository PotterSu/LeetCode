/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

#include "iostream"
#include <vector>

using namespace std;

//1   1
//2   2
//3   4
//4   8

int jumpFloorII(int number)
{
	if(number == 0 || number == 1)
		return 1;
	if(number == 2)
		return 2;
	vector<int> a(number + 1);
	a[1] = 1;
	a[2] = 2;
	for(int i = 3; i <= number; i++)
	{
		a[i] = 1;
		for(int j = 0; j < i - 1; j++)
		{
			a[i] *= 2;
		}
	}
	return a[number];
}

// int jumpFloorII(int number)
// {
// 	if(number == 0 || number == 1)
// 		return 1;
// 	vector<int> a(number + 1);
// 	a[1] = 1;
// 	a[2] = 2;
// 	for(int i = 3; i <= number; i++)
// 	{
// 		int res = 1;
// 		for(int j = 1; j < i; j++)
// 		{
// 			res += a[j];
// 		}
// 		a[i] = res;
// 	}
//
// 	return a[number];
// }

int main()
{
	int result = jumpFloorII(4);
	cout << result << endl;

	return 0;
}
