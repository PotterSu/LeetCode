/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

#include "iostream"
#include <vector>

using namespace std;

int Fibonacci(int n)
{
    if(n == 0)
        return 0;
    vector<int> a(n + 1);
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}

int main()
{
	int result = Fibonacci(3);
	cout << result << endl;

	return 0;
}
