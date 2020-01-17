/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

#include "iostream"
#include <vector>

using namespace std;

int jumpFloor(int number)
{
    if(number == 0)
		return 0;
	if(number == 1)
		return 1;
	if(number == 2)
		return 2;
	vector<int> a(number + 1);
	a[1] = 1;
	a[2] = 2;
	for(int i = 3; i <= number; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[number];
}

int main()
{
	int result = jumpFloor(3);
	cout << result << endl;

	return 0;
}
