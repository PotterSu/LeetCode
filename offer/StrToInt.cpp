/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0
*/

#include "iostream"
#include <vector>

using namespace std;

int StrToInt(string str)
{
    if(str.length() <= 0)
        return 0;
    int flag = 1;
    if(str[0] == '-')
        flag = -1;
    long long number = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(i == 0 && str[i] == '-')
            continue;
        if(i == 0 && str[i] == '+')
            continue;
        if(i >= 0 && str[i] >= '0' && str[i] <= '9')
        {
            number = number * 10 + (str[i] - '0');
            if((flag * number > INT_MAX) || (flag * number < INT_MIN))
            {
                 number=0;
                 break;
            }
        }
        else
        {
            return 0;
        }
    }
    int result = number * flag;

    return result;
}

int main()
{
    string str = "134";
    int result = StrToInt(str);
    cout << result << endl;

	return 0;
}
