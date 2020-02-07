/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

#include "iostream"
#include <vector>

using namespace std;

string s = "";
char a[256] = {0};
//Insert one char from stringstream
void Insert(char ch)
{
    s += ch;
    a[ch] += 1;
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    for(int i = 0; i < s.length(); i++)
    {
        if(a[s[i]] == 1)
        {
            return s[i];
        }
    }
    return '#';
}

int main()
{
    Insert('g');
    Insert('0');
    Insert('g');
    char result = FirstAppearingOnce();
    cout << result << endl;

	return 0;
}
