/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0
*/

#include "iostream"
#include <vector>

using namespace std;

bool isNumeric(char* string)
{
    int length = 0;
    char* ptr = string;
    while(*ptr != '\0')
    {
        length++;
        ptr++;
    }
    cout << length << endl;
    if(length <= 0)
        return false;
    ptr = string;
    int begin = 0;
    if(ptr[0] == '+' || ptr[0] == '-')
        begin = 1;

    int point = 0;
    bool e = false;
    for(int i = begin; i < length; i++)
    {
        if(!e && i > 0 && ptr[i] == '.')
        {
            point++;
            if(point >= 2)
                return false;
        }
        else if(ptr[i] >= '0' && ptr[i] <= '9')
        {
            continue;
        }
        else if(!e && (ptr[i] == 'e' || ptr[i] == 'E'))
        {
            e = true;
            if(ptr[i+1] == '+' || ptr[i+1] == '-' || (ptr[i+1] >= '0' && ptr[i+1] <= '9'))
                continue;
            else
                return false;
        }
        else if((ptr[i] == '+' || ptr[i] == '-'))
        {
            if(i == 0 || ((ptr[i-1] == 'e' || ptr[i-1] == 'E') && (ptr[i+1] >= '0' && ptr[i+1] <= '9')))
                continue;
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    return true;

}

int main()
{
    char* str = "-1E-16";
    bool result = isNumeric(str);
    cout << result << endl;

	return 0;
}
