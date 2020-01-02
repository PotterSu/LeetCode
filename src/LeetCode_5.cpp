/*
5.最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stack"

using namespace std;

string longestPalindrome(string s)
{
	if(s.length() == 0)
	{
		return s;
	}
	int maxLength = 0;
	int nStart = 0;

	int** a = new int*[s.length()];
	for(int i = 0; i < s.length(); i++)
	{
		a[i] = new int[s.length()];
	}

	for(int nRow = 0; nRow < s.length(); nRow++)
	{
		for(int nCol = nRow; nCol < s.length(); nCol++)
		{
			int j = nCol;
			int i = j - nRow;

			//单个字符
			if(j - i == 0)
			{
				a[i][j] = 1;
				if(j - i >= maxLength)
				{
					maxLength = j - i;
					nStart = i;
				}
			}
			else if(j - i == 1 && s[j] == s[i])
			{
				a[i][j] = 1;
				if(j - i >= maxLength)
				{
					maxLength = j - i;
					nStart = i;
				}
			}
			else if(j - i >= 2 && s[j] == s[i] && a[i + 1][j - 1] == 1)
			{
				a[i][j] = 1;
				if(j - i >= maxLength)
				{
					maxLength = j - i;
					nStart = i;
				}
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < s.length(); i++)
	{
		delete[] a[i];
	}
	delete[] a;
	return s.substr(nStart, maxLength + 1);
}

int main()
{
	string s = "cbbd";
	string result = longestPalindrome(s);
	cout << result << endl;

	return 0;
}
