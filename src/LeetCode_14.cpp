/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
 */

#include "iostream"
#include "vector"
#include "string"

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size() == 0)
    {
        return "";
    }
    string result = "";
    string first;
    int minLength = INT_MAX;
    for(int i = 0; i < strs.size(); i++)
    {
        if(strs[i].length() < minLength)
        {
            minLength = strs[i].length();
            first = strs[i];
        }
    }
    for(int j = 0; j < minLength; j++)
    {
        int count = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            if(strs[i][j] == first[j])
            {
                count += 1;
            }
        }
        if(count == strs.size())
        {
            result += first[j];
        }
        else{
            return result;
        }
    }

    return result;
}

int main()
{
    vector<string> strs;
    strs.push_back("");
    strs.push_back("");
    strs.push_back("");

    string result = longestCommonPrefix(strs);

    cout << result << endl;

	return 0;
}
