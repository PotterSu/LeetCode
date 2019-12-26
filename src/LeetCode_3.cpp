/*
3.无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stack"

using namespace std;

int lengthOfLongestSubstring(string s)
{
	int nMaxLength = 0;
	int nMaxLengthTemp = 0;
	int nStringLength = s.length();
	int state[200] = {0};
	int nStart = 0;
	int index = 0;
	int nIndex = 0;
	while(nIndex < nStringLength)
	{
		index = (int)s[nIndex];

		if(state[index] > 0)
		{
			nStart = state[index];
			memset(state, 0, sizeof(int) * 200);
			nMaxLength = nMaxLengthTemp >= nMaxLength ? nMaxLengthTemp : nMaxLength;
			nMaxLengthTemp = 0;
			nIndex = nStart;
		}
		else
		{
			state[index] = nIndex + 1;
			nMaxLengthTemp++;
			nIndex++;
		}
	}
	nMaxLength = nMaxLengthTemp >= nMaxLength ? nMaxLengthTemp : nMaxLength;

	return nMaxLength;
}

int main()
{
	string s = "aabaab!bb";
	int result = lengthOfLongestSubstring(s);
	cout << result << endl;

	return 0;
}
