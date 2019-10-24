/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
 */

#include "iostream"
#include "vector"
#include "string"
#include "stack"

using namespace std;

int strStr(string haystack, string needle)
{
    if(needle.empty())
        return 0;
    int compare_len = needle.length();
    int i = 0;
    while(i < haystack.length())
    {
        if(haystack[i] == needle[0])
        {
            int len = 0;
            for(int j = i; j < i + compare_len; j++)
            {
                if(haystack[j] == needle[len])
                {
                    len++;
                }
                else
                {
                    break;
                }
            }
            if(len == compare_len)
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}

int main()
{
    string haystack = "aaa";
    string needle = "aaaa";
    // string haystack = "hello";
    // string needle = "ll";
    // string haystack = "msfwfsppi";
    // string needle = "pi";

    int index = strStr(haystack, needle);
    cout << index << endl;

	return 0;
}
