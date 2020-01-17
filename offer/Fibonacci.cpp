/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
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
