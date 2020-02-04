/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置,
如果没有则返回 -1（需要区分大小写）.
*/

#include "iostream"
#include <vector>

using namespace std;

int FirstNotRepeatingChar(string str)
{
    vector<int> count(256);
    for(int i = 0; i < str.length(); i++)
    {
        count[str[i]-'A'] += 1;
    }
    for(int i = 0; i < str.length(); i++)
    {
        if(count[str[i]-'A'] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str = "abacb";
    int result = FirstNotRepeatingChar(str);
    cout << result << endl;

	return 0;
}
