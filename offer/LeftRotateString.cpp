/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
*/

#include "iostream"
#include <vector>

using namespace std;

string LeftRotateString(string str, int n)
{
    if(str.length() == 0)
        return str;
    n = n % str.length();
    string front = "";
    string back = "";
    for(int i = 0; i < n; i++)
    {
        front += str[i];
    }
    for(int i = n; i < str.length(); i++)
    {
        back += str[i];
    }
    return back + front;
}

int main()
{
    string str = "abcXYZdef";
    string result = LeftRotateString(str, 3);
    cout << result << endl;

	return 0;
}
