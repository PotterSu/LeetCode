/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

#include "iostream"
#include <vector>

using namespace std;

int Add(int num1, int num2)
{
    int carry = (num1 & num2) << 1;
    int result = num1 ^ num2;
    while(carry != 0)
    {
        int temp = result ^ carry;
        carry = (result & carry) << 1;
        result = temp;
    }
    return result;
}

int main()
{
    int result = Add(4, 3);
    cout << result << endl;

	return 0;
}
