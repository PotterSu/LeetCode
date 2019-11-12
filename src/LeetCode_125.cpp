/*
125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/
#include "iostream"
#include "string"
#include "algorithm"
#include "vector"

using namespace std;

bool isLetter(char c)
{
	if(c >= 'a' && c <= 'z')
		return true;
	if(c >= 'A' && c <= 'Z')
		return true;
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

bool isPalindrome(string s)
{
	int i = 0;
	int j = s.length() - 1;
	for(;i < j;)
	{
		if(!isLetter(s[i]))
		{
			i++;
			continue;
		}
		if(!isLetter(s[j]))
		{
			j--;
			continue;
		}
		if(toupper(s[i]) != toupper(s[j]))
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main()
{
	// string s = "A man, a plan, a canal: Panama";
	string s = "raca b a car";
	bool result = isPalindrome(s);
	cout << result << endl;

	return 0;
}
